/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
       if(head==NULL || head->next==NULL) return head;
       ListNode*lastnode=head->next;
       ListNode* newhead=reverseList(head->next);
        
        lastnode->next=head;
        head->next=NULL;// This step in necessary
        
        return newhead;
        
    }
    
    ListNode*findKthNode(ListNode* head,int k)
    {
        ListNode*temp=head;
        
        int cnt=0;
        while(temp!=NULL && cnt<k-1)
        {
            cnt++;
            temp=temp->next;
            
        }
        
        if(cnt<k-1) return NULL;
        else return temp;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode*prev=head;
        int flag=0;
        while(temp!=NULL)
        {
            ListNode* kthNode=findKthNode(temp,k);
            // cout<<"temp:"<<temp->val<<" kthNode val:"<<kthNode->val<<endl;
            
            if(kthNode==NULL)
            {
                if(flag==0) return head;
                else prev->next=temp;
                
                return head;
            }
            else
            {
                ListNode*nextnode=kthNode->next;
                kthNode->next=NULL;
                ListNode* front=reverseList(temp);
                
                if(flag==0)
                {
                    head=front;
                    prev=temp;
                    flag=1;
                    temp=nextnode;
                }
                else
                {
                    prev->next=front;
                    prev=temp;
                    temp=nextnode;
                }
                
                
            }
          
        }
        
        return head;
    }
};
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
   
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=0;
        while(fast!=NULL && cnt<k)
        {
            fast=fast->next;
            cnt++;
        }
        
        // cout<<"cnt:"<<cnt<<endl;
        if(cnt<k) return rotateRight(head,k-cnt);
        
        else
        {
            if(fast!=NULL){
            while(fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
            
            ListNode* newhead=slow->next;
            fast->next=head;
            slow->next=NULL;
            return newhead;
            }
        }
        
        return head;
    }
};
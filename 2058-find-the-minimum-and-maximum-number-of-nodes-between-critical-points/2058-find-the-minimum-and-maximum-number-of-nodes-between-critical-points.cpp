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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int maxDis=INT_MIN;
        int minDis=INT_MAX;
        
        int ind=0;
        int st=-1;
        int curr=-1;
        int pre=-1;
        ListNode* prev=NULL;
        ListNode * temp=head;
        
        while(temp)
        {
            if(prev!=NULL && temp->next!=NULL)
            {
                if(temp->val>prev->val && temp->val>temp->next->val)
                {
                    if(st==-1)
                    {
                        st=ind;
                        
                    }
                    
                    pre=curr;
                    curr=ind;
                    
                }
                else if(temp->val<prev->val && temp->val<temp->next->val)
                {
                    if(st==-1)
                    {
                        st=ind;
                        
                    }
                    
                    pre=curr;
                    curr=ind;
                }
                
                maxDis=max(maxDis, abs(curr-st));
                if(pre!=-1) minDis=min(minDis,abs(pre-curr));
           }
            
            // cout<<"tempNode:"<<temp->val<<" st:"<<st<<" pre:"<<pre<<" curr:"<<curr<<endl;
              prev=temp;
              temp=temp->next;
            ind++;
            
            }
    
        if(maxDis!=INT_MIN && minDis!=INT_MAX) {
           return {minDis,maxDis};
        }
        else return {-1,-1};
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
       
        ListNode*fast=head;
        ListNode*slow=head;
 
        int cnt=0;
        while(cnt<n)
        {
          
            fast=fast->next;
            cnt++;
        }
        if(fast==NULL) return head->next; // if n==len, then the node which need to be deleted is the first node itself.
        while(fast->next!=NULL)
        {
            fast=fast->next;
          
            slow=slow->next;
           
        }
        
        ListNode* deltenode=slow->next;
        slow->next=slow->next->next;
        delete deltenode;
        return head;
        
            
    }
};
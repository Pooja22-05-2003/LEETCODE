/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TC=O(N1+N2)
// SC=O(N1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mp;
        
        ListNode*temp=headA;
        
        while(temp!=NULL)
        {
             mp[temp]++;
            temp=temp->next;
        }
        
        ListNode* curr=headB;
        
        while(curr!=NULL)
        {
            if(mp.find(curr)!=mp.end()) return curr;
           curr=curr->next;
        }
        
        return NULL;
    }
};
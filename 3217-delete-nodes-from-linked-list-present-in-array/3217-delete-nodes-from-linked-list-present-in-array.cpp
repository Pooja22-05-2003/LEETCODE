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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        ListNode*prev=NULL;
        ListNode* curr=head;
        while(curr)
        {
           if(mp.find(curr->val)!=mp.end())
           {
               // delete the current node
               if(prev!=NULL) prev->next=curr->next;
               else head=curr->next;
               
           }
            if( (mp.find(curr->val)==mp.end())) {
            prev=curr;
            }
            curr=curr->next;
        }
            
        return head;
    }
};
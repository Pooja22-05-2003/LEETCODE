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
    int gcd(int a, int b) 
    { 
        // Find Minimum of a and b 
        int result = min(a, b); 
        while (result > 0) { 
            if (a % result == 0 && b % result == 0) { 
                break; 
            } 
            result--; 
        } 

        // Return gcd of a and b 
        return result; 
    } 
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        ListNode* nextnode=head->next;
        
        while(nextnode!=NULL)
        {
            if(curr!=NULL && nextnode!=NULL)
            {
                int temp=gcd(curr->val,nextnode->val);
                ListNode* newnode=new ListNode(temp);
                newnode->next=nextnode;
                curr->next=newnode;
                
               
            }
             curr=nextnode;
             nextnode=curr->next;
        } 
        
        return head;
            
    }
};
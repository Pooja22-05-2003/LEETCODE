
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL){
            return NULL;
        }
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode*current=dummy;
        int sum,carry=0;
        while(t1!=NULL&&t2!=NULL){
            sum=(t1->val+t2->val+carry)%10;
            carry=(t1->val+t2->val+carry)/10;
            ListNode* newnode=new ListNode(sum);
            current->next=newnode;
            current=newnode;
           
            t1=t1->next;
            t2=t2->next; 


        }
        while(t1!=NULL){
            sum=(t1->val+carry)%10;
            carry=(t1->val+carry)/10;
            ListNode* newnode=new ListNode(sum);
            current->next=newnode;
            current=newnode;
            t1=t1->next;

        }
        while(t2!=NULL){
             sum=(t2->val+carry)%10;
            carry=(t2->val+carry)/10;
            ListNode* newnode=new ListNode(sum);
            current->next=newnode;
            current=newnode;
            t2=t2->next;
            


        }
        if(carry){
            ListNode* newnode=new ListNode(carry);
            current->next=newnode;
            current=newnode;
        }
        return dummy->next;



        
    }
};
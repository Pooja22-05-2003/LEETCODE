
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode*head=new ListNode(-1);
        ListNode*curr=head;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                curr->next=list1;
                list1=list1->next;
                curr=curr->next;
            }
            else 
            {
                curr->next=list2;
                list2=list2->next;
                curr=curr->next;
            }
        }
        
        
        if(!list1) curr->next=list2;
        else if(!list2) curr->next=list1;
        
        return head->next;
    }
};
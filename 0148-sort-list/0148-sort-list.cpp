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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*slow=head;
        ListNode*fast=head->next;// we twist little the original tortoise algo
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
        
    }
    
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*mid=middleNode(head);
        
        ListNode*head1=head;
        ListNode*head2=mid->next;
        mid->next=NULL;
        
        ListNode* leftSortedListHead=sortList(head1);
        ListNode* rightSortedListHead=sortList(head2);
        
        return mergeTwoLists(leftSortedListHead,rightSortedListHead);
    }
};
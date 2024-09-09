class Solution {
public:

    int LLsize(ListNode* head){
        ListNode* temp= head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        
        int size=LLsize(head);
        int target= size/k;
        int rem= size%k;

        if(k>=size){
            while(size){
            ListNode* nextN= head->next;
            head->next=NULL;
            ans.push_back(head);
            head= nextN;
            size--;
            k--;
            }
            while(k){
                ans.push_back(NULL);
                k--;
            }
            
        }

        else{
        while(k){
          ListNode* curr=head;
          int pos=target;

          while(pos!=1){
            curr=curr->next;
            pos--;
          }
          if(rem>0){
            curr=curr->next;
            rem--;
          }
          ListNode* nextN=curr->next;
          curr->next=NULL;
          ans.push_back(head);
          head= nextN;
          k--;
        }
        }
        return ans;
    }
};
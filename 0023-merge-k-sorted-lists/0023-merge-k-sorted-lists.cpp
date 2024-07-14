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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>pq;
        
        ListNode*dummy=new ListNode (-1);
        ListNode*prev=dummy;
        for(int i=0;i<lists.size();i++) 
        {
            // cout<<"i:"<<i<<" val:"<<lists[i]->val<<endl;
            if(lists[i]!=NULL) pq.push({lists[i]->val,lists[i]});
        }
        
        while(!pq.empty())
        {
            // cout<<"pq size:"<<pq.size()<<endl;
            auto curr=pq.top();
            pq.pop();
            
            int nodeval=curr.first;
            
            ListNode*temp=curr.second;
            
            if(temp->next!=NULL) pq.push({temp->next->val,temp->next});
           
            // ListNode* newnode=new ListNode(nodeval);
            prev->next=temp;
            temp->next=NULL;
            prev=prev->next;
            
        }
        
        return dummy->next;
    }
};


/*
Facebook
59
Amazon
47
Microsoft
17
Apple
8
Google
8
ByteDance
8
VMware
4
Adobe
4
Indeed
3
LinkedIn
3
Oracle
3
Yandex
3
Bloomberg
2
Walmart Global Tech
2
Shopee
2
tiktok
2
Sprinklr
2
TuSimple
2

*/
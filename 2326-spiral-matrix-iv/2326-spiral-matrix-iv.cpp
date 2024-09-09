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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
     
        
        vector<vector<int>> matrix(n,vector<int>(m,-1));
        int left=0;
        int right=m-1;
        
        int top=0;
        int bottom=n-1;
        
        
        
        while(left<=right && top<=bottom)
        {
            if(top<=bottom)
            {
                // print left->right
                for(int i=left;i<=right;i++)
                {
                    if(head==NULL) break;
                    else matrix[top][i]=head->val;
                     head=head->next;
                }
                
                top++;
                
                
            }
            
            if(left<=right){
            // print top->bottom
                
                for(int i=top;i<=bottom;i++) 
                {
                    
                    if(head==NULL) break;
                    else matrix[i][right]=head->val;
                     head=head->next;
                }
                right--;
            }
            
             if(top<=bottom)
             {
                // print right->left
                for(int i=right;i>=left;i--)
                {
                    
                    if(head==NULL) break;
                    else matrix[bottom][i]=head->val;
                     head=head->next;
                }
                
                bottom--;
                
             }
            
            if(left<=right){
            // print bottom->top
                
                for(int i=bottom;i>=top;i--) 
                {
                    
                    if(head==NULL) break;
                    else matrix[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
            
            
        }
        
        return matrix;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC=O(N)
// SC=O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        bool left_to_right=true;
        while(!q.empty())
        {
          
            
            int size=q.size();
            vector<int>temp(size);
            
            if(left_to_right){
                for(int i=0;i<size;i++)
                {
                    auto curr=q.front();
                    q.pop();
                    temp[i]=(curr->val);
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                    
                }
                left_to_right=!left_to_right;
            }
            else
            {
                for(int i=size-1;i>=0;i--)
                {
                    auto curr=q.front();
                    q.pop();
                    temp[i]=(curr->val);
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                left_to_right=!left_to_right;
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};
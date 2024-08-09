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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        bool leftToRight=true;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp(size);
            if(leftToRight){
                
            for(int i=0;i<size;i++)
            {
                auto curr=q.front();
                q.pop();
                temp[i]=(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            
                leftToRight=!leftToRight;
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
                leftToRight=!leftToRight;
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};
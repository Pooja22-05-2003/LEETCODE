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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        long long res=0;
        
        // node->ind
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            long long leftind=q.front().second;
            long long rightind=q.back().second;
            
            res=max(res,(rightind-leftind+1));
                
            int  minn=q.front().second;
            long long n=q.size();
            
            while(n--)
            {
                auto curr=q.front().first;
                long long ind=q.front().second;
                ind=ind-minn;
                 q.pop();
                
                if(curr->left) q.push({curr->left,(2*ind+1)});
                if(curr->right) q.push({curr->right,(2*ind+2)});
            
            } 
             
        }
        
        return (int)res;
    }
};
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
    int solve(TreeNode* root, int &res)
    {
        if(root==NULL) return 0;
        
        int l=max(0,solve(root->left,res));
        int r=max(0,solve(root->right,res));
        
        res=max(res,(root->val+l+r));
        
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int temp=solve(root,res);
        return (res==INT_MIN) ?0:res;
    }
};
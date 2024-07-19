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
   
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int ld=0;int rd=0;
        if(root->left)  ld=maxDepth(root->left);
        if(root->right) rd=maxDepth(root->right);
        
        return 1+max(ld,rd);
    }
};
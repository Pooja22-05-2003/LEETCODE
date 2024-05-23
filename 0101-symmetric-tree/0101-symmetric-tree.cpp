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
    bool helper(TreeNode* leftnode, TreeNode* rightnode)
    {
        if(leftnode==NULL && rightnode==NULL) return true;
        if((!leftnode && rightnode) || (leftnode && !rightnode)) return false;
        if((leftnode->val!=rightnode->val)) return false;
        
        bool leftans=helper(leftnode->left,rightnode->right);
        bool rightans=helper(leftnode->right, rightnode->left);
        return (leftans && rightans ) ;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root->left, root->right);
            
    }
};
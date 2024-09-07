/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return NULL;
        if(root==NULL) return NULL;
        
        if(p->val==root->val || q->val==root->val) return root;
        
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        
        if(leftans!=NULL && rightans!=NULL) return root;
        else if(leftans==NULL && rightans!=NULL) return rightans;
        
        return leftans;
        
    }
};
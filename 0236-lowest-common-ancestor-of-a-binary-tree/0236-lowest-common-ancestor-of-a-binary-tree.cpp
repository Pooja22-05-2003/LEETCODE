
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(p==NULL || q==NULL) return NULL;
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        
        if(leftans!=NULL && rightans!=NULL) return root;
        if(leftans!=NULL && rightans==NULL) return leftans;
        return rightans;
        
        
        
    }
};
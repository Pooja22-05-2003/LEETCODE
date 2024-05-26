/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TC=O(logn)
// SC=O(h)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        
        if((root->val>p->val) && (root->val>q->val))
        {
            // search in left half
            return lowestCommonAncestor(root->left,p,q);
        }
        else if((root->val<p->val) && (root->val<q->val))
        {
             // search in right half
            return lowestCommonAncestor(root->right,p,q);
        }
        else 
        {
            // here p and q are dividing in left and right part, means 1 node will be present in left and other in right, so LCA is root node.
            return root;
        }
    }
};
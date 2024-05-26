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
    int findmin(TreeNode* root)
    {
       if(root->left==NULL) return root->val;
       else return findmin(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(key>root->val) root->right= deleteNode(root->right,key);
        else if(key<root->val) root->left= deleteNode(root->left,key);
        
        else
        {
            if(root->left!=NULL && root->right!=NULL)
            {
                int minn= findmin(root->right);
                root->val=minn;
                root->right=deleteNode(root->right,minn);
                return root;
            
            }
            if(root->left!=NULL) return root->left; // only right child of node to be deleted is present//
            if(root->right!=NULL) return root->right;// only left child of node to be deleted is present//
            
            // if both child are present
            // Find the min of the right subtree and make the node val = root->right(min val) and delete the min value node from the right subtree
            else return NULL;
            
            
        }
        
        return root;
            
    }
};
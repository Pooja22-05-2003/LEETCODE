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
        
        if(root->val==key)
        {
            if(root->left && root->right)
            {
                int x=findmin(root->right);
                root->val=x;
                root->right=deleteNode(root->right,x);
                return root;
            }
             if(root->left) return root->left;
             if(root->right) return root->right;
             else return NULL;
        }
         if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key)root->right=deleteNode(root->right,key);
        
        return root;
        
    }
};
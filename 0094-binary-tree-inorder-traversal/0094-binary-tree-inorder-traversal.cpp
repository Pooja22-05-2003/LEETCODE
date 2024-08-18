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

// MORRIS TRAVERAL
// TC=O(N), SC=O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL) return res;
        TreeNode*curr=root;
        
        while(curr)
        {
            if(curr->left==NULL)
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode*prev=curr->left;
                
                while(prev->right && (prev->right!=curr))
                {
                    // traversing the left subtree to make the connection of leftnode right most connection to root
                    prev=prev->right;
                }
                
                if(prev->right==NULL)
                {
                    // it means connection is not created yet
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                   // means destory the connection and now explore the right subtree
                   prev->right=NULL;
                    
                   // before moving curr to right subtree, store the current value in the res
                   res.push_back(curr->val);
                   curr=curr->right; 
                }
            }
        }
        
        return res;
    }
};
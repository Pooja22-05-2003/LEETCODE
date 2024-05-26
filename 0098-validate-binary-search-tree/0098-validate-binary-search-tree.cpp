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

// TC=O(N)
// SC=O(N)
class Solution {
public:
     void solve(TreeNode* root, vector<int>&arr)
    {
        if(root==NULL) return;
        
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
              
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int>arr;
        solve(root,arr);
        
        // find that the inorder traversal is sorted or not, if not sorted that return false
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]>=arr[i+1]) return false;
        }
        return true;
    }
};
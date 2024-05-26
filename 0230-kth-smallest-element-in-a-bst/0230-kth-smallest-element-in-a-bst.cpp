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
/*
1st Appproach : 
Brute Force Approach:
1. Property of BST- It return the traversal in sorted manner, means our arr is sorted
2. At the end of the traversal return arr[k-1] el which is our kth smallest element.

*/

// TC=O(nlogn) // sorting
// SC=O(n) // storing the element in the vector.
class Solution {
public:
    void solve(TreeNode* root, vector<int>&arr)
    {
        if(root==NULL) return;
        
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
              
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        solve(root,arr);
        return arr[k-1];
    }
};
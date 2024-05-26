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
2nd (Optimal Appproach) : 
Brute Force Approach:
1. Property of BST- It return the traversal in sorted manner, Instead of arr , use the cnt variable
2.while doing the inorder traversal (if the cnt==k) return that node.

*/

// TC=O(n) 
// SC=O(h) 
class Solution {
public:
    void solve(TreeNode* root, int&cnt,int &k, int &ans)
    {
        if(root==NULL) return ;
        
        solve(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k)
        {
             ans=root->val; 
            return;
        }
        // arr.push_back(root->val);
        solve(root->right,cnt,k,ans);
        
       
              
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=0;
        solve(root,cnt,k,ans);
        return ans;
     
    }
};
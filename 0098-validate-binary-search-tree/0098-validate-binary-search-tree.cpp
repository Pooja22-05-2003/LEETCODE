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
// TC=O(n)
// SC=O(n)
class Solution {
public:
    bool solve( TreeNode * root,  long long int min, long long int max)
    {
        if(root==NULL) return true;
        
        if(root->val<=min || root->val>=max) return false;
        
        return solve(root->left,min,root->val) && solve(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        long long int min=-10000000000009;
        long long int max=10000000000009;
        return solve(root,min,max);
      
    }
    
    //  bool  isPossible (TreeNode * root, long long int min,long long int max){
    //     if(root==NULL) return true;
    //     if((root->val >min && root->val <max) )return isPossible(root->left,min,root->val) && isPossible (root->right, root->val,max) ;
    //     else return false;
    // }
    // bool isValidBST(TreeNode* root) {
    //     long long int min=-100000000000000;
    //     long long int max=10000000000000;
    //     return isPossible(root,min,max);
    // }
};
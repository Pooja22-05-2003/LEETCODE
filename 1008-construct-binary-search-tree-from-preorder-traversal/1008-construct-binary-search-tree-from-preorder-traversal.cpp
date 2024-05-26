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
    TreeNode* solve(int &ind,vector<int>&arr,int upper_bound) // here must pass ind using the referrence variable.
    {
        if(ind==arr.size() || arr[ind]>upper_bound ) return NULL;
        TreeNode* root=new TreeNode(arr[ind++]);
        root->left=solve(ind,arr,root->val);
        root->right=solve(ind,arr,upper_bound);
        return root;
    }   
        
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
                   // st_ind,arr,INT_MAX val
        return solve(ind,preorder,INT_MAX);
    }
};
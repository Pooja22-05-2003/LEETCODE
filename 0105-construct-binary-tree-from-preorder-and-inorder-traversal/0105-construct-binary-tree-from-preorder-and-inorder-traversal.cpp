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
    unordered_map<int,int>mp;
    int preInd=0;
    TreeNode* solve(int st, int end, vector<int>&preorder, vector<int>&inorder)
    {
        if(st>end) return NULL;
        
        int rootEl=preorder[preInd++];
        TreeNode* root=new TreeNode(rootEl);
        int ind=mp[rootEl];
        root->left=solve(st,ind-1,preorder,inorder);
        root->right=solve(ind+1,end,preorder,inorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // store the indexes of the inorder in the mp;
        int n=preorder.size();
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        
        return solve(0,n-1,preorder,inorder);
    }
};
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
   
    TreeNode* solve(int st, int end, vector<int>& inorder, vector<int>& postorder, int &postInd)
    {
        if(st>end) return NULL;
        
        int rootEl=postorder[postInd--];
        TreeNode* root=new TreeNode(rootEl);
        int ind=mp[rootEl];
        root->right=solve(ind+1,end,inorder,postorder,postInd);
        root->left=solve(st,ind-1,inorder,postorder,postInd);
       
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         int n=inorder.size();
         int postInd=n-1;
        
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        
        return solve(0,n-1,inorder,postorder,postInd);
    
    }
};
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

// Approach 2: (Using DFS )
/*
While reaching any level , check if the size of the array is smaller than the ans.size, then push that element , else not push it.
*/

// Tc=O(N)
// SC=O(N)
class Solution {
public:
    void preorder(TreeNode* root, int level, vector<int>&ans)
    {
        if(root==NULL) return;
        
        if(ans.size()<level) ans.push_back(root->val);
        
        // We are doing preorder (root, left right), but changing little because we need to traverse the right side view , so first put the right node first, the  left node.
        preorder(root->right,level+1,ans);
        preorder(root->left, level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        preorder(root,1,ans);
        return ans;
        
    }
};
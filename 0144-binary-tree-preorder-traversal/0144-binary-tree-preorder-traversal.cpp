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

// Iterative Preorder Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans; 
        if(root==NULL) return ans;
        
        stack<TreeNode*>st;
        st.push(root);
        
        while(!st.empty())
        {
            auto curr=st.top(); st.pop();
            ans.push_back(curr->val);
            
            if(curr->right) st.push(curr->right); // order is root left right , so if u will push left at last , then only it will come first out.
            if(curr->left) st.push(curr->left);
        
            
        }
        return ans;
    }
};
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

// Approach 1:
// Using Level Wise Traversal
// Put the last node in the ans vector at each level.

// Tc=O(N)
// SC=O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>ans;
        while(!q.empty())
        {
            int n=q.size();
            TreeNode* curr=NULL;
            for(int i=0;i<n;i++)
            {
                curr=q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            ans.push_back(curr->val);
        }
        
        return ans;
        
    }
};
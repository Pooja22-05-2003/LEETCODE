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

// Inorder Traversal= left root right
// TC=O(N)
// SC=O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        vector<int>ans;
        
        if(root==NULL) return ans;
        TreeNode* curr=root;
        
       
        
        while(true)   // ⭐⭐Here while(!st.empty condition is false because initially , I have not pushed any val)
        {  
           if(curr==NULL)
           {
               // check whether the stack is empty or not
               if(st.empty()) break;
               curr=st.top();
               st.pop();
               cout<<"curr->val:"<<curr->val<<endl;
               ans.push_back(curr->val);
               curr=curr->right;
           }
            else
            {
                st.push(curr);
                curr=curr->left;
            }
        }
        
        return ans;
    }
};
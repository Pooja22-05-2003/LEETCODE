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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        long long  res=0;
        while(!q.empty())
        {
            int minn=q.front().second;
            long long l=q.front().second;
            long long r=q.back().second;
            res=max(res,(r-l+1));
            double n=q.size();
            
            while(n--)
            {
                auto curr=q.front();
                q.pop();
                TreeNode* currnode=curr.first;
                long long ind=curr.second;
                ind=ind-minn;
                
                if(currnode->left) q.push({currnode->left,(2*ind+1)});
                if(currnode->right) q.push({currnode->right,(2*ind+2)});
            }
        }
        
        return (int)res;
    }
};
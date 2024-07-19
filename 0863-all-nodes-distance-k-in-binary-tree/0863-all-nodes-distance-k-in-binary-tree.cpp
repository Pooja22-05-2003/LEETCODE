/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>mp;
    
    void BFS(TreeNode* target, int k, vector<int>&res)
    {
        set<TreeNode*>vis;
        
        queue<TreeNode*>q;
        q.push(target);
        vis.insert(target);
        
        while(!q.empty())
        {
            if(k==0) break;
            
            int n=q.size();
            while(n--)
            {
                auto curr=q.front();
                q.pop();
                
                if(curr->left && vis.find(curr->left)==vis.end())
                {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                
                 if(curr->right && vis.find(curr->right)==vis.end())
                {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                
                if(mp.count(curr) && vis.find(mp[curr])==vis.end())
                {
                    q.push(mp[curr]);
                    vis.insert(mp[curr]);
                }
            }
            k--;
                
                
        }
        
        
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        
        if(root->left) mp[root->left]=root;
        inorder(root->left);
        if(root->right) mp[root->right]=root;
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        
        vector<int>res;
        BFS(target,k,res);
        return res;
    }
};
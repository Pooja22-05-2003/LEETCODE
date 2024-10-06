
class Solution {
public:
    void preorder(unordered_map<TreeNode*, TreeNode*>&mp, TreeNode* root,TreeNode*parent)
    {
        if(root==NULL) return;
        mp[root]=parent;
        
        preorder(mp,root->left,root);
        preorder(mp,root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>mp;
        unordered_set<TreeNode*>vis;
        preorder(mp,root,NULL);
        
        queue<pair<TreeNode*,int>>q;
        vis.insert(target);
        q.push({target,0});
        
        vector<int>res;
        
        while(!q.empty()){
            int size=q.size();
            int level=q.front().second;

            if(level==k) 
            {
                vector<int>res;
                while(size--)
                {
                   auto curr=q.front().first;q.pop();
                   res.push_back(curr->val);
                    
                }
                return res;
            }
            
            while(size--){
            TreeNode* curr=q.front().first;
            int level=q.front().second;
            q.pop();
            if(curr->left && vis.find(curr->left)==vis.end()){
                q.push({curr->left,level+1});
                vis.insert(curr->left);
            }
            if(curr->right && vis.find(curr->right)==vis.end()){
                q.push({curr->right,level+1});
                vis.insert(curr->right);
            }
            
            if(mp[curr]!=NULL  && vis.find(mp[curr])==vis.end()){
                q.push({mp[curr],level+1});
                vis.insert(mp[curr]);
             }
            }
        }
        
        return res;
    }
};
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
    void preorder(int col,int row,TreeNode* root,map<int,map<int,multiset<int>>>&mp)
    {
        if(root==NULL) return;
        
        mp[col][row].insert(root->val);
        preorder(col-1,row+1,root->left,mp);
        preorder(col+1,row+1,root->right,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        
        // {col->{row/level,{elements at co-ordinate{row,col}}}}
        map<int,map<int,multiset<int>>>mp;
        preorder(0,0,root,mp);
        
        for(auto col:mp)
        {
            vector<int>temp;
            for(auto row:col.second)
            
            {
                for(auto value:row.second)
                    
                {
                   temp.push_back(value); 
                }
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};
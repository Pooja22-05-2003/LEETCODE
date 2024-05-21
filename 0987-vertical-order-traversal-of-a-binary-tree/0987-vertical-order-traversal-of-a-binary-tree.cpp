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

// TC=O(n)
// SC=O(n)+O(n)
class Solution {
public:
    void preorder(int y , int level,TreeNode*root, map<int,map<int,multiset<int>>>&mp)
    {
        if(root==NULL) return;
        
        mp[y][level].insert(root->val);
        preorder(y-1,level+1,root->left,mp);
        preorder(y+1,level+1,root->right,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // y axis-> {level,{val}}
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        preorder(0,0,root,mp);
        
        for(auto y : mp)
        {
            vector<int>temp;
            
            for(auto level: y.second)
            {
                for(auto value:level.second) // level.second means iterating all the values in the particular leve
                {
                    temp.push_back(value);
                }
            }
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};
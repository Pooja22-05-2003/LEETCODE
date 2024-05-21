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

// TC=O(N)
// SC=O(N)
/*
Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        bool left_to_right=true;
        while(!q.empty())
        {
          
            
            int size=q.size();
            vector<int>temp(size);
            
            if(left_to_right){
                for(int i=0;i<size;i++)
                {
                    auto curr=q.front();
                    q.pop();
                    temp[i]=(curr->val);
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                    
                }
                left_to_right=!left_to_right;
            }
            else
            {
                for(int i=size-1;i>=0;i--)
                {
                    auto curr=q.front();
                    q.pop();
                    temp[i]=(curr->val);
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                left_to_right=!left_to_right;
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};
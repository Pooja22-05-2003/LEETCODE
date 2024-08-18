/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string res="";
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto curr=q.front(); q.pop();
            if(curr==NULL) res.append("N,");
            else
            {
                res.append(to_string(curr->val)+",");
            }
            
            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        
        stringstream ss(data); // ss is the object of the string stream class
        
        string curr;
        getline(ss,curr,','); // getline will iterate through ss object on string data and store the curr string(Char) in the curr string
        
        
        TreeNode* root=new TreeNode(stoi(curr));
        
        queue<TreeNode*>q;
        q.push(root);
        
        
        while(!q.empty())
        {
            auto currnode=q.front();q.pop();
            
             getline(ss,curr,','); 
            
            if(curr=="N") currnode->left=NULL;
            else
            {
                TreeNode* leftnode=new TreeNode(stoi(curr));
                currnode->left=leftnode;
                q.push(leftnode);
            }
            
            getline(ss,curr,',');
            
            if(curr=="N") currnode->right=NULL;
            else
            {
                TreeNode* rightnode=new TreeNode(stoi(curr));
                currnode->right=rightnode;
                q.push(rightnode);
            }
        }
        
        return root;
    }
};


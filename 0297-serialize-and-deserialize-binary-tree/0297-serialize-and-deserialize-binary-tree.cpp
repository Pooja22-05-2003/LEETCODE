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


    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
           auto curr=q.front();q.pop();
           if(curr==NULL) res+="#,";
           else
           {
               res+=to_string(curr->val)+",";
               q.push(curr->left);
               q.push(curr->right);
           }
        }
        
        return res;
            
    }

  
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        
        string str;
        
        getline(s,str,',');
        
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto curr=q.front();q.pop();
            
            getline(s,str,',');
            
            if(str=="#")
            {
                curr->left=NULL;
            }
            else
            {
                TreeNode* leftnode=new TreeNode(stoi(str));
                curr->left=leftnode;
                q.push(leftnode);
            }
            
            
            getline(s,str,',');
            
            if(str=="#")
            {
                curr->right=NULL;
            }
            else
            {
                TreeNode* rightnode=new TreeNode(stoi(str));
                curr->right=rightnode;
                q.push(rightnode);
            }
        }
        
        return root;
        
    }
};


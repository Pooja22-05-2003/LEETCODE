class Trie {
public:
    
    struct TrieNode
    {
         bool isEndofWord;
         TrieNode * children[26]; // this array will store the adresses
    };
    
    
    // It will create only one node for us.
    TrieNode * getNode()
    {
        TrieNode* newnode=new TrieNode();
        newnode->isEndofWord=false;
        
        for(int i=0;i<26;i++)
        {
           newnode-> children[i]=NULL;
        }
        
        return newnode;
    }
    TrieNode* root;
    Trie() {
        
        root=getNode();
        
    }
    
    void insert(string word) {
        TrieNode * curr=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            int ind=c-'a';
            
            if(curr->children[ind]==NULL)
            {
                TrieNode *temp=getNode();
                curr->children[ind]=temp;
               
            }
             curr=curr->children[ind];
        }
        
        curr->isEndofWord=true;
    }
    
    bool search(string word) {
        TrieNode * curr=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            int ind=c-'a';
            
            if(curr->children[ind]==NULL)
            {
                return false;
               
            }
             curr=curr->children[ind];
        }
        
       if(curr!=NULL && curr->isEndofWord==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode * curr=root;
        int i=0;
        for(i=0;i<prefix.size();i++)
        {
            char c=prefix[i];
            int ind=c-'a';
            
            if(curr->children[ind]==NULL)
            {
                return false;
               
            }
             curr=curr->children[ind];
        }
        
        if(i==prefix.length()) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
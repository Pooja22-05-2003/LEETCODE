/*
Insertion: The time complexity of inserting a word into the Trie is O(m), where m is the length of the word. This is because in the worst case, we may need to traverse through all the characters of the word to insert it into the Trie.

Search: The time complexity of searching for a word in the Trie is O(m), where m is the length of the word being searched for. Similar to insertion, in the worst case, we may need to traverse through all the characters of the word to find it in the Trie.

Starts With: The time complexity of checking whether the Trie contains any word with a given prefix is also O(m), where m is the length of the prefix. As with insertion and search, in the worst case, we may need to traverse through all the characters of the prefix to determine if it exists as a prefix of any word in the Trie.

*/
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
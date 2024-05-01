class Solution {
public:
    string reversePrefix(string word, char ch) {
        int st=0;
        int end=-1;
        
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==ch) 
            {
                end=i;
                break;
            }
        }
        
        if(end==-1) return word;
        else
        {
            while(st<end)
            {
                int temp=word[st];
                word[st]=word[end];
                word[end]=temp;
                
                st++;
                end--;
            }
        }
        
        return word;
        
    }
};
class Solution {
public:
    bool valids(string s, unordered_map<char,int>mp, int i, int j)
    {
        bool ans=true;
        for(auto it:mp)
        {
            if(it.second>1) return false;
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int maxlen=0;
        unordered_map<char,int>freq;
        int i=0;
        int j=0;
      
        while(j<s.size())
        {
            // cout<<"i:"<<i<<"j:"<<j<<endl;
            freq[s[j]]++;
            while(i<j && !valids(s,freq,i,j))
            {
                
                freq[s[i]]--;
                i++;
            }
            
           
            int len=j-i+1;
            // cout<<"len:"<<len<<endl;
           
            maxlen=max(maxlen,len);
            j++;
    
        }
        return maxlen;
     }
    
};
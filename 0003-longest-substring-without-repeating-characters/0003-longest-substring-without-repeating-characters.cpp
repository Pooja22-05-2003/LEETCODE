class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0; // edge case
        // if(s==" " ) return 1;
        int maxlen=1;
        vector<int>mp(255,-1);
        int i=0;
        int j=0;
        // int len=0;
        while(j<n)
        { 
            if(mp[s[j]]>=i)
            {
                i=mp[s[j]]+1;
               
                mp[s[j]]=j;
                 j++;
                continue;
               
            }
            
            maxlen=max(maxlen,(j-i+1));
            mp[s[j]]=j;
           
            j++;
        }
        
        return maxlen;
    }
};
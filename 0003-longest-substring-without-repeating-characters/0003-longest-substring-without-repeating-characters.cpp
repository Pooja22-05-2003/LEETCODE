class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0; // edge case
        // if(s==" " ) return 1;
        int maxlen=1;
        unordered_map<char,int>mp;
        
        for(int i=0;i<n;i++)
        {
            int len=1;
            mp[s[i]]++;
            
            for(int j=i+1;j<n;j++)
            {
                if(mp.find(s[j])!=mp.end())
                {
                    mp.clear();
                    len=1;
                    break;
                    
                }
                maxlen=max(maxlen,j-i+1);// i to j-1 is valid
                
                mp[s[j]]++;
            }
        }
        
        return maxlen;
    }
};
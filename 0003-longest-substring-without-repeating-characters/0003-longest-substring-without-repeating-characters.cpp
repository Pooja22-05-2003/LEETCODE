class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0; // edge case
        // if(s==" " ) return 1;
        int maxlen=1;
        unordered_map<char,int>mp;
        int i=0;
        // int len=0;
        while(i<n)
        { 
            mp[s[i]]=i;
            // len++;
            
            int j=i+1;
            while(j<n)
            {
                if(mp.find(s[j])!=mp.end())
                {
                    // cout<<"i:"<<i<<" j:"<<j<<endl;
                    i=mp[s[j]];
                    mp.clear();
                    // i=j-1;
                    // len--;
              
                    break;
                    
                }
                 // len++;
                maxlen=max(maxlen,j-i+1);// i to j-1 is valid
                
                mp[s[j]]=j;
               
                j++;
            }
            cout<<"i:"<<i<<endl;
            i++;
        }
        
        return maxlen;
    }
};
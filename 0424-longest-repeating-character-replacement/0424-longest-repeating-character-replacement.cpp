class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>mp(255,0);
        int n=s.size();
        int i=0;
        int j=0;
        int res=0;
        int maxlen=INT_MIN;
        while(j<n)
        {
              mp[s[j]]++;
            
              maxlen=max(maxlen,mp[s[j]]);
              // cout<<"j:"<<j<<" maxlen:"<<maxlen<<endl;
            
            // window is from i to j
            
            
                while(((j-i+1)-maxlen)>k)
                {
                    // cout<<"jj:"<<j<<" ii:"<<i<<endl;
                    mp[s[i]]--;
                    i++;
                    for(int k=0;k<255;k++)
                    {
                        maxlen=max(maxlen,mp[k]);
                    }
                }
        
                res=max(res,((j-i+1)));
                // cout<<"j:"<<j<<" res:"<<res<<endl;
                j++;
            
        }
        
        return res;
    }
    
    
    /*
    A  B  A  B
    0  1  2  3
    i
          j
    
    maxlen=2 , res=3
    
    
    arr A=2,
        B=2,
    
    
    */
};
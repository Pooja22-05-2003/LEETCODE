class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int res=0;
        int maxlen=0;
        
        int i=0;
        int j=0;
        
        unordered_map<int,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            maxlen=max(maxlen,mp[s[j]]);
            
            while(i<=j && ((j-i+1)-maxlen)>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
                
                for(auto it:mp)
                {
                    maxlen=max(maxlen,it.second);
                }
                
            }
            
            res=max(res,(j-i+1));
            j++;
        }
        
        return res;
    }
};
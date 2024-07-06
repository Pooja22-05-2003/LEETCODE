class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int>mp;
        
        for(auto it: t) mp[it]++;
        
        int i=0;
        int j=0;
        
        int reqlen=t.size();
        int minlen=INT_MAX;
        int minSt=-1;
        
        while(j<n)
        {
            if(mp[s[j]]>0) reqlen--;
            
            mp[s[j]]--;
            
            while(reqlen==0)    
            {
                if(j-i+1<minlen)
                {
                    minlen=j-i+1;
                    minSt=i;
                }
                
                mp[s[i]]++;
                
                if(mp[s[i]]>0)
                {
                    reqlen++;
                }
                
                i++;
            }
        
            
            j++;
        }
        
        if(minSt==-1) return "";
        else return s.substr(minSt,minlen);
    }
};
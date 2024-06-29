class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        
        int j=0;
        int i=0;
        int n=s.size();
        
        int reqCount=t.size();
        int minlen=INT_MAX;
        int minStart=-1;
        while(j<n)
        {
            if(mp[s[j]]>0)
            {
                
                reqCount--;
            }
            
            mp[s[j]]--;
            
            while(reqCount==0)
            {
                // maintain the start of the minlength substring
                if(minlen>(j-i+1))
                {
                    minlen=j-i+1;
                    minStart=i;
                }
                
                mp[s[i]]++;
              
                
                if(mp[s[i]]>0) reqCount++;
                  i++;
            }
            j++;
        }
        
        if(minlen==INT_MAX) return "";
        else return s.substr(minStart,minlen);
    }
};
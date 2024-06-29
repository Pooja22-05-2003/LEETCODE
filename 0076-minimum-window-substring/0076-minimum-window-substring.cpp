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
            
            mp[s[j]]--; // ⭐This condition need to come out of the if because if the character is not present in t, then also we are decreasing its frequency and it was going in -ve.
         
            
            while(reqCount==0)
            {
                // maintain the start of the minlength substring
                if(minlen>(j-i+1))
                {
                    minlen=j-i+1;
                    minStart=i;
                }
                
                mp[s[i]]++;
              
                
                if(mp[s[i]]>0) reqCount++; // ⭐This if condition is needed, because if some char freq is -2 and i did ++ so it get -1 but this character is not present in the target t, so we will not add it in the reqCount.
                  i++;
            }
            j++;
        }
        
        if(minlen==INT_MAX) return "";
        else return s.substr(minStart,minlen);
    }
};
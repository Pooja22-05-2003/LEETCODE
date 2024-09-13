class Solution {
public:
    bool check(unordered_map<char,int>&mp)
    {
        for(auto it:mp) 
        {
            if(it.second>1) return false;
        }
        
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int res=0;
        unordered_map<char,int>mp;
         int i=0;
         int j=0;
        
         while(j<n)
         {
            mp[s[j]]++;
            
            while(i<=j && check(mp)==false)
            {
                mp[s[i]]--;
                i++;
            }
             
            res=max(res,(j-i+1));
             
            j++;
         }
        
            return res;
        }

};
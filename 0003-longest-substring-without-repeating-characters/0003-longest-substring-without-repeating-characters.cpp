// TC=O(N)
// SC=O(1)

/*
Amazon-49, Microsoft-29,Facebook-23,Bloomberg-23,Apple-16
Google-13,Spotify-10,Adobe-6,Uber-5,VMware-5,Yahoo-4,Goldman Sachs-4,Oracle-4,Walmart Global Tech-3,Salesforce-3,Paypal-2,Samsung-2,Intuit-2,Yandex-2,Zoho-2,JPMorgan-2
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0; // edge case
        // if(s==" " ) return 1;
        int maxlen=1;
        vector<int>mp(255,-1); // We are using array and not map, because map will initlize all the char value to 0, and then it will give wrong ans for test case s="au"
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
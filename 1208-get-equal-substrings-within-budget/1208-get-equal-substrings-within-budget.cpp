// Sliding Window
// TC=O(n)
// SC=O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int currCost=0;
        int n=s.size();
        int maxlen=0;
        while(j<n)
        {
            currCost+=abs(s[j]-t[j]);
            
            while(currCost>maxCost)
            {
               currCost -=abs(s[i]-t[i]);
                i++;
            }
            
            int len=(j-i+1);
            maxlen=max(maxlen,len);
            
            
            j++;
        }
        
        return maxlen;
    }
};
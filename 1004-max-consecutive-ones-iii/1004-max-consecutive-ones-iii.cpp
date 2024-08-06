// TC=O(N)
// SC=O(1)


// Eliminating the k loop.
class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        int n=s.size();
        int maxlen=0;
        int j=0;
        int i=0;
        
        while(j<n)
        {
            if(s[j]==0) k--;
            
            while(i<j && k<0)
            {
                if(s[i]==0) k++;
                i++;
            }
            
            if(k>=0)  maxlen=max(maxlen,(j-i+1));
            j++;
        }
        
        return maxlen;
    }
};
// Two Pointer
// TC=O(n)
// SC=O(1)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        
        int i=0;
        int j=0;
        
        while(i<n1 && j<n2)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(j==n2) return 0;
        if(j==0) return n2;
        return(n2-j);
      
    }
};
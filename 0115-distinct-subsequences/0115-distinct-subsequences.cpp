/*
Amazon-4,Mathworks-3,Google-2
*/
class Solution {
public:
   
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<double>curr(n2+1,0);
        vector<double>prev(n2+1,0);
        
        
        // right shifting , because base case consider <0
        
        // for any index i, if the j is at 0 then we return 1
        prev[0]=1;
        curr[0]=1;//⭐ I missed this case
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                   
                    if(s[i-1]==t[j-1]) curr[j]=prev[j-1]+prev[j];
                    else curr[j]=prev[j];
            }
            prev=curr;
        }
        return (int)prev[n2];
    }
};
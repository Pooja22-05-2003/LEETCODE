class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int cnt=0;
        // for len=1
        for(int i=0;i<n;i++) 
        {
            dp[i][i]=1;
            cnt++;
        }
        
        // for len=2
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]) 
            {
                dp[i][i+1]=1;
                cnt++;
            }
            else dp[i][i+1]=0;
        }
        
        int len=3;
        
        while(len<=n){
            int i=0;
            while(i<n){
                int j=i+len-1;
                if(j<n){
                if(s[i]==s[j] && dp[i+1][j-1]==1) {
                    dp[i][j]=1;
                    cnt++;
                }
                }
                
                i++;
            }
            
            len++;
        }
        
        return cnt;
    }
};
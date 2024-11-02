class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)  dp[0][0]=grid[0][0];
                else{
                int opt1=INT_MAX;
                int opt2=INT_MAX;
                if(i-1>=0) opt1=grid[i][j]+dp[i-1][j];//up
                if(j-1>=0) opt2=grid[i][j]+dp[i][j-1];//left
                    
                dp[i][j]=min(opt1,opt2);
                }
                
            }
        }
        return dp[n-1][m-1];
    }
};
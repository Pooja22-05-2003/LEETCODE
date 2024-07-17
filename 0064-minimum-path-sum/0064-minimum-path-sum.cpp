class Solution {
public:
    int solve(int m ,int n, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(m<0 || n<0) return 0;
        if(m==0 && n==0) return grid[0][0];
        
        if(dp[m][n]!=-1) return dp[m][n];
        int up=10000000;
        int left=10000000;
        if(m-1>=0) up= grid[m][n]+solve(m-1,n,grid,dp);
        if(n-1>=0) left=grid[m][n]+solve(m,n-1,grid,dp);
        
        return dp[m][n]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};
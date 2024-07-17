class Solution {
public:
     int solve(int row,int col,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid)
    {
        if(row<0 || col<0) return 0;
        if(obstacleGrid[row][col]==1) return 0;
        if(row==0 && col==0) return 1;
        
       
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        return dp[row][col]=solve(row-1,col,dp,obstacleGrid)+solve(row,col-1,dp,obstacleGrid);
    }
    int uniquePaths(int m, int n,vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return uniquePaths(m,n,obstacleGrid);
    }
};
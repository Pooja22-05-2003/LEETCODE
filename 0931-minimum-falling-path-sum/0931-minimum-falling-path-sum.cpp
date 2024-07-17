class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=INT_MAX;
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
              dp[m-1][j]=matrix[m-1][j];
        }
        
        for(int r=n-2;r>=0;r--)
        {
            for(int c=n-1;c>=0;c--){
            int down_left=INT_MAX;
            int down=INT_MAX;
            int down_right=INT_MAX;
            if(r+1<m && c-1>=0) down_left=matrix[r][c]+dp[r+1][c-1];
            if(r+1<m) down=matrix[r][c]+dp[r+1][c];
            if(r+1<m && c+1<n) down_right=matrix[r][c]+dp[r+1][c+1];

             dp[r][c]=min(down_left, min(down,down_right));
            }
        }
        
        for(int j=0;j<n;j++)
        {
            res=min(res,dp[0][j]);
        }
        
        return res;
    }
};
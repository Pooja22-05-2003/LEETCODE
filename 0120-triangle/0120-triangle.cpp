class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            dp[m-1][j]=triangle[m-1][j];
        }
        
        for(int r=m-2;r>=0;r--)
        {
            for(int c=r;c>=0;c--)
            {
                int down=triangle[r][c]+dp[r+1][c];
                int down_right=triangle[r][c]+dp[r+1][c+1];

                 dp[r][c]=min(down,down_right);
            }
        }
        return dp[0][0];
    }
};
/*
2
3 4
6 5 7
4 1 8 3

*/
class Solution {
public:

  int solve(int r, int c,int m,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
       
        if(r==m-1) return triangle[r][c] ;
     
        if(dp[r][c]!=-1) return dp[r][c];
        int down=triangle[r][c]+solve(r+1,c,m,triangle,dp);
        int down_right=triangle[r][c]+solve(r+1,c+1,m,triangle,dp);
        
        return dp[r][c]=min(down,down_right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return solve(0,0,m,triangle,dp);
    }
};
/*
2
3 4
6 5 7
4 1 8 3

*/
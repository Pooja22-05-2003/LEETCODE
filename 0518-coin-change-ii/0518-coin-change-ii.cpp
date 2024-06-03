// Tabulation
// TC>=O(n*amount)
// SC=O(n*amount) 
class Solution {
public:
 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        if(amount==0) return 1; // edge case
        
        for(int j=0;j<=amount;j++)
        {
            if(j%coins[0]==0) dp[0][j]=1;
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake=dp[ind-1][j];
                int take=0;
                if(coins[ind]<=j)
                {
                   take=dp[ind][j-coins[ind]];
                }
        
              dp[ind][j]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
};
// Tabulation
// TC=O(n*sum)
// SC=O(n*sum)

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX-100));
        
        for(int j=0;j<=amount;j++)
        {
            if ((j%coins[0])==0) dp[0][j] = j/coins[0]; //⭐⭐Mistake , here u did wrong and instead of j , u  used the amount variable.
//             so pls use the jth variable.
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake=dp[ind-1][j];
                int take=INT_MAX-100;
                if(j>=coins[ind])
                {
                  take=1+dp[ind][j-coins[ind]];
                 } 
                
                dp[ind][j]=min(take,nottake);
            }
        }
        
        int ans=dp[n-1][amount];
        
        if(ans==INT_MAX-100) return -1; // ⭐⭐Edge case, when ans is -1 return INT_MAX-100
        else return ans;
    }
};
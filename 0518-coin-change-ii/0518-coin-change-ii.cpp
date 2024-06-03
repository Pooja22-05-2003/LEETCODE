// Memoization
// TC>=O(n*amount)
// SC=O(n*amount) + O(n) [more tha n because recursion tree depth can go beyond n, as we can take 1 elemenet more than 1 times also.]
class Solution {
public:
    int solve(int ind, vector<int>&coins, int amount,vector<vector<int>>&dp)
    {
        // base case
        if(ind==0)
        {
            // if the target is 0 OR the target is divisible by the arr[0] element , then we can achive the target, so return 1
            return (amount%coins[0]==0); //⭐⭐Here u need to write (amount%coins[0]==0) and not (amount%coins[0]){becuase in this case it will understand that we need remainder as 1}
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nottake=solve(ind-1,coins,amount,dp);
        int take=0;
        if(coins[ind]<=amount)
        {
            take=solve(ind,coins,amount-coins[ind],dp);
        }
        
        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};
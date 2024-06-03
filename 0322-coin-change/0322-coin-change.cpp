// Memoization
// TC=O(n*sum)
// SC=O(n*sum)

class Solution {
public:
    int solve(int ind, int target, vector<int>&coins, vector<vector<int>>&dp)
    {
        //⭐⭐Unique edge cases, different from knapsack problems
//         Here only when we reach the last ind we will return something
        
        // ⭐⭐Must return INT_MAX-100
        if(ind==0)
        {
        if ((target%coins[ind])==0) return target/coins[ind];
        return INT_MAX-100;
        }
       
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=solve(ind-1,target,coins,dp);
        int take=INT_MAX-100;
        if(target>=coins[ind])
        {
            take=1+solve(ind,target-coins[ind],coins,dp);
        }
        
        // cout<<"ind:"<<ind<<" take:"<<take<<" nottake:"<<nottake<<endl;
        return dp[ind][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        
        if(ans==INT_MAX-100) return -1; // ⭐⭐Edge case, when ans is -1 return INT_MAX-100
        else return ans;
    }
};
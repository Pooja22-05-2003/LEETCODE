// DP-Explore all the possible ways and return the max profit
// Memoization
// TC=O(n*2)
// SC=O(n*2) + O(n)

//⭐⭐Here u cannot start the recursion from the back, because buy and sell we need to start from day 0
class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp)
    {
        // base case
        
        if(ind==prices.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==1)
        {
           // buy the stock on the ith day
           int opt1=-1*prices[ind]+solve(ind+1,0,prices,dp);
            
          // not buy the stock on the ith day
           int opt2=0+solve(ind+1,1,prices,dp);
            
          profit=max(opt1,opt2);
           
        }
        else
        {
           // sell the stock on the ith day
           int opt1=prices[ind]+solve(ind+1,1,prices,dp);
            
          // not sell the stock on the ith day
           int opt2=0+solve(ind+1,0,prices,dp);
            
          profit=max(opt1,opt2);
        }
        
        return dp[ind][buy]=max(0,profit);
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
       int buy=1; // initilally we can buy any stock
       return solve(0,buy,prices,dp); 
    }
};
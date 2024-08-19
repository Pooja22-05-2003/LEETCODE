class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp)
    {
        
        if(ind==prices.size()) return 0;
        int opt1=0;
        int opt2=0;
        int profit=0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            opt1=max((-prices[ind]+solve(ind+1,1-buy,prices,dp)),(solve(ind+1,buy,prices,dp)));
            profit=opt1;
        }
        else
        {
            opt2=max((+prices[ind]+solve(ind+1,1-buy,prices,dp)),(0+solve(ind+1,buy,prices,dp)));
            profit=opt2;
        }
        
        return dp[ind][buy]=max(0,profit);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=true;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,buy,prices,dp);
    }
};
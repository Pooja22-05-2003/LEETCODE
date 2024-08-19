class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=1;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int opt1=0;
                int opt2=0;
                int profit=0;

               
                if(buy)
                {
                    opt1=max((-prices[ind]+dp[ind+1][0]),(dp[ind+1][buy]));
                    profit=opt1;
                }
                else
                {
                    opt2=max((prices[ind]+dp[ind+1][1]),(dp[ind+1][buy]));
                
                    profit=opt2;
                } 
                 dp[ind][buy]=profit;
            }
          
        }
        return dp[0][1];
    }
};
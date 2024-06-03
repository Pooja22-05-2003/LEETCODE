// Space Optimization
// TC=O(n*sum)
// SC=O(sum)

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,INT_MAX-100);
        vector<int>curr(amount+1,INT_MAX-100);
        
        for(int j=0;j<=amount;j++)
        {
            if ((j%coins[0])==0) prev[j] = j/coins[0]; //⭐⭐Mistake , here u did wrong and instead of j , u  used the amount variable.
//             so pls use the jth variable.
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake=prev[j];
                int take=INT_MAX-100;
                if(j>=coins[ind])
                {
                  take=1+curr[j-coins[ind]];
                 } 
                
                curr[j]=min(take,nottake);
                
            }
            prev=curr;
        }
        
        int ans=prev[amount];
        
        if(ans==INT_MAX-100) return -1; // ⭐⭐Edge case, when ans is -1 return INT_MAX-100
        else return ans;
    }
};
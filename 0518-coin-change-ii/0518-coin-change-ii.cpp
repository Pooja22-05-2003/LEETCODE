// Space Optimization
// TC>=O(n*amount)
// SC=O(n*amount) 
class Solution {
public:
 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);
        if(amount==0) return 1; // edge case
        
        for(int j=0;j<=amount;j++)
        {
            if(j%coins[0]==0) prev[j]=1;
        }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake=prev[j];
                int take=0;
                if(coins[ind]<=j)
                {
                   take=curr[j-coins[ind]];
                }
        
              curr[j]=take+nottake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
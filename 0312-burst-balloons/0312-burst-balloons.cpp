
class Solution {
public:
  
    int maxCoins(vector<int>& arr) {
        int n=arr.size();
      
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        
        int n1=arr.size();
        vector<vector<int>>dp(n1,vector<int>(n1,0));
        
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++) // ⭐j will  start from i and not i+1
            {
                int maxi=INT_MIN;
        
             
                for(int ind=i;ind<=j;ind++)
                {
                    int temp=arr[i-1]*arr[ind]*arr[j+1] + dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,temp);
                }

                 dp[i][j]=maxi;
            }
        }
        
        return dp[1][n];
        
    }
};


// Google
// 7
// Microsoft
// 6
// Apple
// 4
// Bloomberg
// 4
// Uber
// 3
// Amazon
// 2
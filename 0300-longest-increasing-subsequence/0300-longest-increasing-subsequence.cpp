class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxlen=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--){
               if(nums[i]>nums[j]) dp[i]=max(dp[i],1+dp[j]);
            }
            maxlen=max(maxlen,dp[i]);
        }
        
        return maxlen;
    }
};
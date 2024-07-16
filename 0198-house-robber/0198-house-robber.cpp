class Solution {
public:
    int solve(int ind, vector<int>&nums,vector<int>&dp)
    {
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int opt1=nums[ind]+solve(ind-2,nums,dp);
        int opt2=solve(ind-1,nums,dp);
        
        return dp[ind]=max(opt1,opt2);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums.size()-1,nums,dp);
    }
};
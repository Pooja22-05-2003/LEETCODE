class Solution {
public:
    int solve(int ind, int prev_ind, vector<int>&nums,vector<vector<int>>&dp)
    {
        if(ind==nums.size()) return 0;
        
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int nottake=0+solve(ind+1,prev_ind,nums,dp);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
        {
            take=1+solve(ind+1,ind,nums,dp);
        }
        
        return dp[ind][prev_ind+1]=max(nottake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int prev_ind=-1;
        return solve(0,prev_ind,nums,dp);
    }
};
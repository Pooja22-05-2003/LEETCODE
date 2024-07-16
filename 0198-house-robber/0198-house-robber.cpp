class Solution {
public:
   
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        
        dp[0]=nums[0];
        if(nums.size()>1) dp[1]=max(nums[0],nums[1]);
        
        for(int ind=2;ind<nums.size();ind++)
        {
            int opt1=INT_MIN;
            int opt2=INT_MIN;
            if(ind-2>=0) opt1=nums[ind]+dp[ind-2];
            if(ind-1>=0) opt2=dp[ind-1];
            dp[ind]=max(opt1,opt2);
        }
        
        return dp[nums.size()-1];
        
    }
};
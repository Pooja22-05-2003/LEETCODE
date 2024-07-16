class Solution {
public:
     int rob1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
       vector<int>arr1;
        vector<int>arr2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        
        return max(rob1(arr1),rob1(arr2));
    }
};
// TC=O(n)
// SC=O(n)
class Solution {
public:
        // Space Optimization code of House Robber II
      int rob1(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);

        int prev2=nums[0];
        if(n==1) return prev2; // ⭐⭐This is the edge case in case of space optimization only
        int prev1=0;
        if(n>=2) prev1=max(nums[0],nums[1]); // ⭐⭐Edge case- dp[1] can only be intialize if the size of the n is greater than or equal  to 2 and intitlize the dp[1] = max(nums[1],nums[0])
        for(int i=2;i<n;i++)
        {
            // Take
            int opt1=nums[i]+prev2;
            // not take 
            int opt2=prev1;

            int curr=max(opt1,opt2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int>arr1,arr2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        return max(rob1(arr1),rob1(arr2));
    }
};
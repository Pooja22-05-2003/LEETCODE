class Solution {
public:
       void solve(int ind, int n , vector<int>&nums, vector<int>&temp, vector<vector<int>>&res, int target)
        {
            // base case
            if(target==0){
            res.push_back(temp);
            }
            if(target<0) return ;
           
            for(int i=ind;i<n;i++)
            {
                if(i!=ind && nums[i]==nums[i-1]) continue;
                
                if(nums[i]<=target){
                temp.push_back(nums[i]);
                solve(i+1,n,nums,temp,res,target-nums[i]);
                temp.pop_back();
                }

            }
        }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,n,nums,temp,res,target);
        return res;
    }
};
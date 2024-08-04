class Solution {
public:
    void solve(int ind, int n , vector<int>&nums, vector<int>&temp, vector<vector<int>>&res)
    {
        // base case
        res.push_back(temp);

        for(int i=ind;i<n;i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,res);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>temp;
        solve(0,n,nums,temp,res);
        return res;
    }
};
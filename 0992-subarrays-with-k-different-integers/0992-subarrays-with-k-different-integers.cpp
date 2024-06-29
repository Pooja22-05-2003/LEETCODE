// Approach1:
// TC=2*(2*n)==O(n)
// SC=O(n)
class Solution {
public:
    int solve(vector<int>&nums, int k)
    {
        int res=0;
        int i=0;
        int j=0;
        int n=nums.size();
        
        unordered_map<int,int>mp;
        
        while(j<n)
        {
            mp[nums[j]]++;
            
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            res+=(j-i+1);  // it will add all the subarray of size <=k ending at index j
            j++;
        }
        
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        // find decreasing point
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind=i;
                break;
            }
        }
        
        if(ind==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        // find one element in right part of increasign slop, which is just greater than the ind element
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }
        
        reverse(nums.begin()+ind+1,nums.end());
        
       
        
    }
};
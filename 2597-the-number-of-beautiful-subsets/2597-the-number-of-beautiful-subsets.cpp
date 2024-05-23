class Solution {
public:
    int solve(int i,int k ,vector<int>&nums,unordered_map<int,int>&m)
    {
        if(i==nums.size())return 1;  
        
        int c=0;

        c+=solve(i+1,k,nums,m);// not_take

        if(m[nums[i]-k]==0)///if nums[i]-k not present the we take
        {
            m[nums[i]]=1;
            c+=solve(i+1,k,nums,m);/// take
            m[nums[i]]=0;
        }
        return   c; 
    }
     
    int beautifulSubsets(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;

        return  solve(0,k,nums,m)-1;
    }
};
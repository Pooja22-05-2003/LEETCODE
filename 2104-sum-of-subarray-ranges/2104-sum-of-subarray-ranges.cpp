class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int minn=nums[i];
            int maxx=nums[i];
            
            for(int j=i+1;j<n;j++)
            {
                minn=min(minn,nums[j]);
                maxx=max(maxx,nums[j]);
                res+=(maxx-minn);
            }
        }
        
        return res;
    }
};
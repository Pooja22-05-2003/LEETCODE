class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        
        int n=nums.size();
        int i=0;
        int j=0;
        int res=0;
        int sum=0;
        int cnt0=0;
        while(j<n)
        {
            sum+=nums[j];
            
            while(i<j && (nums[i]==0 || sum>k))
            {
                if(nums[i]==0) cnt0++;
                else 
                {
                cnt0=0;
                sum-=nums[i];
                }
                i++;
            }
           
            if(sum==k) res=res+1+cnt0; 
            j++;
           
        }
        
       
        return res;
    }
};
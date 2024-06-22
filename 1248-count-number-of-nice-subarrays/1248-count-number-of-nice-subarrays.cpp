class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // convert the odd numbers->1
        // convert the even numbers -> 0
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        
        // count the number of subarray having sum equal to k
        
        unordered_map<int,int>mp;
        mp[0]=1;
        
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            
            mp[sum]++;
        }
        
        return cnt;
    }
};
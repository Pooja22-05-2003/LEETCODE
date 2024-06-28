class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            cout<<"sum:"<<sum<<endl;
            if(mp.find(sum-k)!=mp.end())
            {
                // cout<<"i:"<<i<<endl;
              res+=mp[sum-k];  
            }
            mp[sum]++;
        }
        return res;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        
        int lastInd=0;
        int res=1;
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int j=i-1;j>=0;j--)
            {
            
                if(nums[j]<nums[i] && dp[i]<(1+dp[j]))
                {
                    // cout<<"i:"<<i<<" dp[i]:"<<dp[i]<<" j:"<<j<<" dp[j]:"<<dp[j]<<endl;
                    dp[i]=max(dp[i],1+dp[j]);
                    hash[i]=j;
                }
                
                // cout<<dp[i]<<endl;
            }
            
            if(dp[i]>res)
            {
            res=max(res,dp[i]);
            lastInd=i;
            }
        }
        
        vector<int>temp;
        
        while(lastInd!=hash[lastInd])
        {
            temp.push_back(nums[lastInd]);
            lastInd=hash[lastInd];
        }
        
        reverse(temp.begin(),temp.end());
        for(auto it: temp)
        {
            cout<<it<<" ";
        }
        return res;
    }
};
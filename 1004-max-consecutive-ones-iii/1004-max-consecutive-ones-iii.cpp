class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
        // for(int i=0;i<n;i++)
        // {
        //     int cnt0=0;
        //     for(int j=i;j<n;j++)
        //     {
        //         if(nums[j]==0) cnt0++;
        //         if(cnt0>k) break;
        //         len=max(len,j-i+1);
        //     }
        // }
        
        if(k==0)
        {
            int maxlen=0;
            int len=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==1) len++;
                else 
                {
                    maxlen=max(maxlen,len);
                    len=0;
                }
                
            }
            maxlen=max(maxlen,len);
            return maxlen;
        }
        
        int i=0;
        int j=0;
        int cnt0=0;
        
        while(j<n)
        {
            if(nums[j]==0) cnt0++;
            
            while(i<j && cnt0>k)
            {
                if(nums[i]==0)
                {
                    cnt0--;
                }
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        
        return len;
    }
};
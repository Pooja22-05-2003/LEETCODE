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
            
            while(i<j && (nums[i]==0 || (sum>k)))
            {
                if(nums[i]==0) cnt0++;
                else 
                {
                    // cout<<"i:"<<i<<endl;
                    // This else is needed because without this, it will fail on the below test case
                    
                    // [0,1,1,1,1]
                    // Correct output:3
                    cnt0=0;
                }
                
                sum-=nums[i];
                i++;
            }
           
            if(sum==k) res=res+1+cnt0; 
            j++;
           
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // convert odd numbers to 1, then this que is exactly similat to prev ques
        //930. Binary Subarrays With Sum
        
       vector<int>arr(nums.size());
        
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]%2==0) arr[i]=0;
           else arr[i]=1;
       }
        
       return numSubarraysWithSum(arr,k);
    }
};
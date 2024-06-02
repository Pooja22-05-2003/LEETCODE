// Space Optimized Code
// TC=O(n*sum)
// SC=O(n*sum)
class Solution {
public:
     bool isSubsetSum(vector<int>&arr, int sum){
        // code here 
        int n=arr.size();
        vector<bool>prev(sum+1,false);
        vector<bool>curr(sum+1,false);
        
        // dp[0][0]=true;
        if(arr[0]<=sum) prev[arr[0]]=true; //⭐⭐Edge case(We can only access prev[arr[0]]), if the size is greater than arr[0]
         /*
         
         Edge case:
         [99,1], here sum/2=50.
         Now , we have only created array of size 50, so we can't access arr[99]
         */
    
        
        prev[0]=true;
        curr[0]=true;
        int i=1;
        while(i<n)
        {
            int j=1;
            while(j<=sum)
            {
                
                bool nottake=prev[j];
                bool take=false;
                if(j>=arr[i]) take=prev[j-arr[i]];
                bool ans=(take | nottake);
       
                curr[j]=ans;
                // cout<<"i:"<<i<<" j:"<<j<<" dp[i][j]:"<<dp[i][j]<<endl;
            
        
        
                j++;
            }
            
            prev=curr;
            i++;
        }
        
       
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it : nums)
        {
            sum+=it;
        }
        
        if((sum%2!=0) || (nums.size()==1)) return false;
        
        //⭐⭐[Key Point] If we want to parition the whole array into 2 subsets such that both the subset sum should be equal, then it is only possible, if both the subset have sum=totalsum/2.
   
       bool ans= isSubsetSum(nums,(sum/2));
        
        return ans;
    }
};
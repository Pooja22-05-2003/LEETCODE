class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int n=nums.size();
       int st=0;
       int end=n-1;
       int ans=n;
       while(st<=end)
       {
           
           int mid=(st+end)/2;
           if(nums[mid]==target) return mid;
           if(nums[mid]<target)
           {
               
                st=mid+1;
                
           }
           else 
           {
                ans=mid;
               end=mid-1;
           }
       }
        
        return ans;
    }
};
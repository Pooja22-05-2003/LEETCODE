// In the binary search , we eliminate one part, it can be left or right.
// search the part which is sorted, then compare the min of that part with the global minimum . and eliminate the part which is sorted and repeat this , until st<=end.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=nums.size()-1;
        int ans=INT_MAX;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            ans=min(ans,nums[mid]); // ⭐Must add this condition
            // check whether left part is sorted?
            if(nums[st]<=nums[mid]) {
                ans=min(ans,nums[st]); //...in the sorted part minimum element is always the first element.
                st=mid+1;
            }
            else
            {
                if(mid+1<n) ans=min(ans,nums[mid+1]);
                end=mid-1;
                
            }
        }
        
        return ans;
    }
};
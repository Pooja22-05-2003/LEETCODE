class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        bool ans=false;
        int st=0;
        int end=n-1;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
           if(nums[mid]==target) return true;
            
            // check which part is the sorted part.
            else if(nums[st]==nums[mid] && nums[mid]==nums[end]) {
                st++;
                end--;
            }

         
            else if(nums[st]<=nums[mid])
            {
                // left part is sorted
                if(nums[mid]>=target && nums[st]<=target)
                {
                    end=mid-1;
                }
                else st=mid+1;
            }
            else
            {
                // right part is sorted
                 if(nums[mid]<=target && nums[end]>=target)
                {
                    st=mid+1;
                }
                else end=mid-1;
            }
        }
        
        return ans;
    }
};
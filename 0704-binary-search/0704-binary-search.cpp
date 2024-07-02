// TC=O(nlogn)
// SC=O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            // cout<<"mid:"<<mid<<endl;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target)
            {
                end=mid-1;
            }
            else st=mid+1;
        }
        
        return -1;
    }
};
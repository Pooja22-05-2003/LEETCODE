class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        
        int l=-1;
        int r=-1;
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(nums[mid]==target)
            {
                // find the first and last occ
                
                int x=mid;
                l=x;r=x;
                while(x>=0 && nums[x]==target)
                {
                    l=x;
                    x--;
                }
                
                int y=mid;
                
                while(y<n && nums[y]==target)
                {
                    r=y;
                    y++;
                }
                
                return {l,r};
            }
            else if(nums[mid]<target)
            {
                st=mid+1;
            }
            else end=mid-1;
        }
        
        return {l,r};
    }
};
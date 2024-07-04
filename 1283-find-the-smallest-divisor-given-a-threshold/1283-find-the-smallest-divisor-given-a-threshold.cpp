// TC=O(n(log(maxElement)))
// SC=O(1)
class Solution {
public:
    bool check(int d, vector<int>&nums,int thr)
    {
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            // cnt+=floor(nums[i]/d);
            if(nums[i]%d==0) cnt+=(nums[i])/d;
            else cnt+=((nums[i])/d)+1;
        }
        
        
        if(cnt<=thr) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int min_el=1;
        int max_el=INT_MIN;
        
        for(auto el:nums){
            // min_el=min(min_el,el);
            max_el=max(max_el,el);
        }
        
        // for(int i=1;i<=max_el;i++)  // ⭐⭐Here we cannot run min_value from min_el, ans can also be 1 even if it was not present in this array.
        // {
        //     if(check(i,nums,threshold)==true) return i;
        // }
        
        int st=1;
        int end=max_el; // Threshold in the constraints it is given that it will always be greater than equal to nums.size();
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(mid-1==0 && check(mid,nums,threshold)==true ) return mid;
            if(check(mid,nums,threshold)==true && check(mid-1,nums,threshold)==false) return mid;
            
            else if(check(mid,nums,threshold)==true) end=mid-1;
            else st=mid+1;
        }
        
        return INT_MAX;
    }
};
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
       
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
           if((nums[i]&1)==0) cnt++; // must put brackets around (nums[i]&1)
        }
        
        return (cnt>=2)?1:0;
    }
};
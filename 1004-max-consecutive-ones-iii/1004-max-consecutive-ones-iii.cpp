class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt1=0;
        int res=0;
        while(j<n){
            
            if(nums[j]==0) cnt1++;
            
            while(cnt1>k){
                if(nums[i]==0){
                    cnt1--;
                   
                }
                
                 i++;
            }
            
            res=max(res,(j-i+1));
            j++;
        }
        
        return res;
    }
};
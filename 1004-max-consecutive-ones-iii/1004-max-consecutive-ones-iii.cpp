// TC=O(N)
// SC=O(1)


// Eliminating the k loop.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int len=0;
       
     
        int i=0;
        int j=0;
        int cnt0=0;
        
        while(j<n)
        {
            if(nums[j]==0) cnt0++;
            
            while(i<j && cnt0>k )
            {
                if(nums[i]==0) cnt0--;
                i++;
            }
            if(cnt0<=k){
            len=max(len,j-i+1);
            }
            j++;
        }
        
        return len;
    }
};
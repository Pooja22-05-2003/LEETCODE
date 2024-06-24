class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
       
        
        // ans.push_back(arr);
        
        int end=pow(2,n);
        
        for(int i=0;i<end;i++)
        {
            
             vector<int>arr;
            for(int j=0;j<30;j++)
            {
                if((i>>j)&1)
                {
                    arr.push_back(nums[j]);
                }
            }
            
            ans.push_back(arr);
            
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<pair<int,int>>nums;
        
        for(int i=0;i<v.size();i++) nums.push_back({v[i],i});
        sort(nums.begin(),nums.end());
        
        int left=0;
        int right=nums.size()-1;
        
        vector<int>res;
        while(left<right)
        {
            
            if((nums[left].first+nums[right].first)==target) 
            {
        
                res.push_back(nums[left].second);
                res.push_back(nums[right].second);
                return res;
            }
            else if((nums[left].first+nums[right].first)<target) left++;
            else right--;
                
        }
        
        return res;
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        vector<int>ans;
        for(auto it : nums)
        {
            freq[it]++;
        }
        
        for(auto it : freq)
        {
            if(it.second==1) ans.push_back(it.first);
        }
        
         sort(ans.begin(),ans.end());
        return ans;
    }
};
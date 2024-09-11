class Solution {
public:
    void solve(vector<int>&nums, unordered_map<int,int>&mp)
    {
        stack<int>st;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            
            while(!st.empty() && (st.top()<nums[i])) st.pop();
            if(st.empty())
            {
                mp[nums[i]]=-1;
            }
            else mp[nums[i]]=st.top();
            st.push(nums[i]);
        }
    }   
        
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        solve(nums2,mp);
        
        vector<int>res;
        
        for(int i=0;i<nums1.size();i++)
        {
            res.push_back(mp[nums1[i]]);
        }
        
        return res;
            
    }
};
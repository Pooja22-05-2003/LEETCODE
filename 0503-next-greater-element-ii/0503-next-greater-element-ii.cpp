class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        
        for(int i=nums.size()-2;i>=0;i--) st.push(nums[i]);
        
        vector<int>res(nums.size(),-1);
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i]) st.pop();
        
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            
            st.push(nums[i]);
        }
        
        return res;
    }
};
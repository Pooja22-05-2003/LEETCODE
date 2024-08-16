class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(i==nums2.size()-1) 
            {
                st.push(nums2[i]);
                mp[nums2[i]]=-1;
            }
            else
            {
                // pop all the smallest element than the current element
                while(!st.empty() && st.top()<=nums2[i]) st.pop();
                
                // store the ans corresponding to the current element
                if(!st.empty()) mp[nums2[i]]=st.top();
                else mp[nums2[i]]=-1;
                
                st.push(nums2[i]);
                
            }
            
            
        }
        
        vector<int>res(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            res[i]=mp[nums1[i]];
        }
        
        return res;
    }
};
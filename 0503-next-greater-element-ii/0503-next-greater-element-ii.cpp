class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res(n,-1);
        vector<int>arr;
        
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back(nums[i]);
        }
        
        for(int i=0;i<nums.size()-1;i++)
        {
            arr.push_back(nums[i]);
        }
        
        int totalel=(nums.size()*2)-1;
        
        // for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        cout<<endl;
        stack<int> st;
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(i>=n)
            {
                while(!st.empty() && st.top()<=arr[i]) st.pop();
            }
            else{
                 while(!st.empty() && st.top()<=arr[i]) st.pop();
                 if(!st.empty()) res[i]=st.top();
                
            }
            
            
            st.push(arr[i]);
            
           
            // cout<<"i:"<<i<<" st.size():"<<st.size()<<endl;
        }
        
        return res;
    }
};
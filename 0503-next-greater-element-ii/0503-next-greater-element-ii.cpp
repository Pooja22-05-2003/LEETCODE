class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        for(int i=(2*n-1);i>=0;i--)
        {
            while(!st.empty() && arr[i%n]>=st.top()) st.pop();
            
            if(i<n)
            {
                if( st.empty())
                {
                    res[i]=-1;
                }
                else res[i]=st.top();
                
            }
            
            st.push(arr[i%n]);
        }
        
        return res;
    }
};
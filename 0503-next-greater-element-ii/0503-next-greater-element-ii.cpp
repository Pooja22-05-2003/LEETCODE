// TC=O(4n)
// SC=O(2n)+O(n)// n is for res
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>res(n,-1);
        stack<int>st;
        for(int i=(2*n-2);i>=0;i--) // O(2n)
        {
            while(!st.empty() && arr[i%n]>=st.top()) st.pop();//O(2n)
            
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
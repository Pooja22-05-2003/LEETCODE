// TC=O(3*n)
// SC=O(3*n)
class Solution {
public:
    void nextSmallerLeft( vector<int>&nsl, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=0;i<arr.size();i++)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]>=el) st.pop(); //⭐missed equal to in both nsl and nsr
            
            if(st.empty()) nsl[i]=-1;
            else nsl[i]=st.top();
            st.push(i);
        }
    }
    
    void nextSmallerRight(vector<int>&nsr, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]>=el) st.pop();
            
            if(st.empty()) nsr[i]=arr.size();
            else nsr[i]=st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        int maxarea=0;
        if(n==1) return arr[0]*1;
        
        vector<int>nsl(n,-1); // nsl=next smaller left
        vector<int>nsr(n,n); // nsr=next smaller right
        
        nextSmallerLeft(nsl,arr);
        nextSmallerRight(nsr,arr);
        for(int i=0;i<arr.size();i++)
        {
            int el=arr[i];         
            
            int smallerleft=nsl[i];
            int smallerright=nsr[i];
           
            int area=(smallerright-smallerleft-1)*arr[i];
            maxarea=max(maxarea,area);
        }
        
        
        return maxarea;
        
    }
};
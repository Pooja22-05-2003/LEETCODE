// TC=O(3*n)==O(n)
// SC=O(2*n)==O(n)
class Solution {
public:
    void NSL(vector<int>& arr,vector<int>&NextSmallerLeft)
    {
        NextSmallerLeft[0]=-1;
        stack<int>st;
        st.push(0);
        
        for(int i=1;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) NextSmallerLeft[i]=-1;
            else NextSmallerLeft[i]=st.top();
            
            st.push(i);
        }
        
        
    }
    
    
    
    
    void NSR(vector<int>& arr,vector<int>&NextSmallerRight)
    {
        int n=arr.size();
        NextSmallerRight[n-1]=n;
        stack<int>st;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) NextSmallerRight[i]=n;
            else NextSmallerRight[i]=st.top();
            
            st.push(i);
        }
    }
    
    
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int Mod=1e9+7;
        
        vector<int>NextSmallerLeft(n,n);
        vector<int>NextsmallerRight(n,n);
        
        NSL(arr,NextSmallerLeft);
        NSR(arr,NextsmallerRight);
        
        long long  sum=0;
        for(int i=0;i<n;i++)
        {
            long long  Num_Left= Num_Left=i-NextSmallerLeft[i];
            
            long long Num_Right=NextsmallerRight[i]-i;
            
            long long total=Num_Left*Num_Right;
            sum=sum%Mod;
            sum+=(total*arr[i])%Mod;
            sum=sum%Mod;
        }
        
        return sum;
        
    }
};
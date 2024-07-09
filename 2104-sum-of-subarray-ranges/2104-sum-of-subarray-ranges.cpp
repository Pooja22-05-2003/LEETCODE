class Solution {
public:
    
    void nextSmallerLeft( vector<int>&nsl, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=0;i<arr.size();i++)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]>el) st.pop(); // equal to sign will come in subarray , so no need to add equal to.
            
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
            
            while(!st.empty() && arr[st.top()]>=el) st.pop();// In this que, here equal will not be added, because we are moving in right in actual ans calcaultion , so if that element will come in right that will count in itself.
            
            if(st.empty()) nsr[i]=arr.size();
            else nsr[i]=st.top();
            st.push(i);
        }
    }
    void nextGreaterLeft( vector<int>&nsl, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=0;i<arr.size();i++)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]<el) st.pop(); // equal to sign will come in subarray , so no need to add equal to.
            
            if(st.empty()) nsl[i]=-1;
            else nsl[i]=st.top();
            st.push(i);
        }
    }
    
    void nextGreaterRight(vector<int>&nsr, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]<=el) st.pop();// In this que, here equal will not be added, because we are moving in right in actual ans calcaultion , so if that element will come in right that will count in itself.
            
            if(st.empty()) nsr[i]=arr.size();
            else nsr[i]=st.top();
            st.push(i);
        }
    }
    long long subArrayRanges(vector<int>& arr) {
         int n=arr.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        nextSmallerLeft(nsl,arr);
        nextSmallerRight(nsr,arr);
      
        
        long long ans=0;
        for(int i=0;i<n;i++){
            int l=i-nsl[i];
            int r=nsr[i]-i;
            
            ans=(ans+(((long long)l*r*arr[i])));
            //ans=(ans+(l2*arr[i])%mod)%mod;
        }
        
        vector<int>ngl(n);
        vector<int>ngr(n);
        nextGreaterLeft(ngl,arr);
        nextGreaterRight(ngr,arr);
      
        
        long long  ans1=0;
        for(int i=0;i<n;i++){
            int l=i-ngl[i];
            int r=ngr[i]-i;
            
            ans1=(ans1+(((long long)l*r*arr[i])));
            //ans=(ans+(l2*arr i])%mod)%mod;
        }
        
        return (ans1)-(ans);
        
        
    }
};
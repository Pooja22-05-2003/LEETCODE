class Solution {
public:
const int mod=1e9+7;
   void nextSmallerLeft( vector<int>&nsl, vector<int>arr)
    {
        stack<int>st;
        
        for(int i=0;i<arr.size();i++)
        {
            int el=arr[i];
            
            while(!st.empty() && arr[st.top()]>=el) st.pop(); // equal to sign will come in subarray , so no need to add equal to.
            
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
            
            while(!st.empty() && arr[st.top()]>el) st.pop();// In this que, here equal will not be added, because we are moving in right in actual ans calcaultion , so if that element will come in right that will count in itself.
            
            if(st.empty()) nsr[i]=arr.size();
            else nsr[i]=st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        nextSmallerLeft(nsl,arr);
        nextSmallerRight(nsr,arr);
        //int n=arr.size();
      
         for(int i=0;i<n;i++) cout<<nsl[i]<<" ";
        cout<<endl;
        
        for(int i=0;i<n;i++) cout<<nsr[i]<<" ";
        cout<<endl;
        
        long ans=0;
        for(int i=0;i<n;i++){
            int l=i-nsl[i];
            int r=nsr[i]-i;
            
            ans=(ans+(((long)l*r*arr[i])%mod))%mod;
            //ans=(ans+(l2*arr[i])%mod)%mod;
        }
        return (int)ans;
    }
};
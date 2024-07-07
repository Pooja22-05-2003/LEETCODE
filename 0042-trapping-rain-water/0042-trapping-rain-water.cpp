class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        
        int leftmax=0;
        
        for(int i=0;i<n;i++)
        {
            leftmax=max(leftmax,arr[i]);
            prefix[i]=leftmax;
        }
        
        int rightmax=0;
        
        for(int i=n-1;i>=0;i--)
        {
            rightmax=max(rightmax,arr[i]);
            suffix[i]=rightmax;
        }
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<prefix[i]<<",";
//         }
//         cout<<endl;
        
//          for(int i=0;i<n;i++)
//         {
//             cout<<suffix[i]<<",";
//         }
        cout<<endl;
        int res=0;
        for(int i=1;i<n-1;i++)
        {
            int temp=min(prefix[i],suffix[i+1])-arr[i];
            if(temp>=0) res+=temp;
            // cout<<"i:"<<i<<" res:"<<min(prefix[i],suffix[i+1])-arr[i]<<endl;
        }
        
        return res;
    }
};
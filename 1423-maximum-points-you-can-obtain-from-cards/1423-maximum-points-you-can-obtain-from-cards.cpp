class Solution {
public:
    int solve(vector<int>&A , int n , int k ){
       vector<int> prefix(n+2,0);
       vector<int> suffix(n+2,0);

       for(int i=1;i<=n;i++){
          prefix[i]=prefix[i-1]+A[i];
          // cout<<"i:"<<i<<" prefix[i]:"<<prefix[i]<<endl;
       }
       for(int i=n;i>=1;i--){
          suffix[i]=suffix[i+1]+A[i];
          // cout<<"i:"<<i<<" suffix[i]:"<<suffix[i]<<endl;
       }

    
       int maxSum=0;

       int i=0;
       while(i<=k){
          int j=(n-(k-i))+1;
           // cout<<"ii:"<<i<<" jj:"<<j<<endl;
          int sum=prefix[i]+suffix[j];
           // cout<<"sum:"<<sum<<endl;
          maxSum=max(maxSum,sum);

          i++;
       }

       return maxSum;



}
    int maxScore(vector<int>& a, int k) {
        // convert the array to 1 based indexing.
        int n=a.size();
        vector<int>arr(a.size()+1);
        
        for(int i=1;i<=n;i++)
        {
            arr[i]=a[i-1];
        }
        
        int ans=solve(arr,n,k);
        return ans;
    }
};
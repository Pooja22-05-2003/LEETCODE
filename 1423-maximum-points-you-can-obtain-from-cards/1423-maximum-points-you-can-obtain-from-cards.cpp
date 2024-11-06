class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int res=0;
        int sum=0;
        
        for(int i=0;i<k;i++) sum+=arr[i];
        res=sum;
        int cnt=1;
        int j=n-1;
        int i=k-1;
        while(cnt<=k){
            
            sum-=arr[i];
            // cout<<"summ:"<<sum<<endl;
            sum+=arr[j];
            // cout<<"sum:"<<sum<<endl;
            res=max(res,sum);
            cnt++;
            i--;
            j--;
        }
        
        return res;
    }
};
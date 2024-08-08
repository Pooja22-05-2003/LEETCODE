class Solution {
public:
      bool check(int kk, vector<int>& arr, int k)
    {
        int cnt=0;
       
        for(int i=0;i<arr.size();i++)
        {
           cnt+=(arr[i]/kk)+((arr[i]%kk)!=0);
            // cout<<"i:"<<kk<<" i:"<<i<<" cnt:"<<cnt<<endl;
            if(cnt>k) break;
            
        }
        // cout<<"i:"<<kk<<" cnt:"<<cnt<<endl;
        return (cnt<=k);
    }
    int smallestDivisor(vector<int>& arr, int k) {
         int n=arr.size();
         // long long int temp=m*k;
        // if((temp)>n) return -1;
       
        int minn=INT_MAX;
        int maxx=INT_MIN;
        
        for(auto el: arr)
        {
            minn=min(minn,el);
            maxx=max(maxx,el);
        }
        
        int st=1;
        int end=maxx;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            // cout<<"mid:"<<mid<<" st:"<<st<<" end:"<<end<<endl;
            if(mid==1 && check(mid,arr,k)==true) return mid;
            if(check(mid,arr,k)==true && check(mid-1,arr,k)==false) return mid;
            if(check(mid,arr,k)==true) end=mid-1;
            else st=mid+1;
        }  
        return -1;    
    }
};
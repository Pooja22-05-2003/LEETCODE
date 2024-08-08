class Solution {
public:
    bool check(int kk, vector<int>& arr, int m, int k)
    {
        int cnt=0;
        int continuos=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=kk) 
            {
                continuos++;
                if(continuos==k)
               {
                    
                cnt++;
                continuos=0;
               }
            }
            else continuos=0;
            
        }
        // cout<<"i:"<<kk<<" cnt:"<<cnt<<endl;
        return (cnt>=m);
    }
    
    
    int minDays(vector<int>& arr, int m, int k) {
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
        
        int st=minn;
        int end=maxx;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            // cout<<"mid:"<<mid<<" st:"<<st<<" end:"<<end<<endl;
            if(mid==1 && check(mid,arr,m,k)==true) return mid;
            if(check(mid,arr,m,k)==true && check(mid-1,arr,m,k)==false) return mid;
            if(check(mid,arr,m,k)==true) end=mid-1;
            else st=mid+1;
        }  
        return -1;    
    }
};
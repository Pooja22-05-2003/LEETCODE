class Solution {
public:
    bool check(int k,vector<int>& arr, int h)
    {
        int t=0;
        for(auto it: arr)
        {
            t+=(it/k)+((it%k)!=0);
            if(t>h) break;
        } 
      
        return (t<=h);
            
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        
        int n=arr.size();
        int maxx=INT_MIN;
        for(auto it: arr)  maxx=max(maxx,it);
        int st=1;
        int end=maxx;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            if(mid==1 && check(mid,arr,h)==true) return mid;
            if(check(mid,arr,h)==true && check(mid-1,arr,h)==false) return mid;
            if(check(mid,arr,h)==true) end=mid-1;
            else st=mid+1;
         
        }
        
        return -1;
    }
};
class Solution {
public:
    bool check(int x, vector<int>&arr, int ball)
    {
        int cnt=1;
        int prev=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            int curr=arr[i];
            
            if((curr-prev)>=x)
            {
                cnt+=1;
                prev=curr;
            }
            
            
            if(cnt==ball) break;
        }
        
        return (cnt==ball);
    }
    int maxDistance(vector<int>& arr, int m) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int st=1;
        int end=arr[n-1]-arr[0];
        int ans=0;
        while(st<=end)
        {
            int mid=(end+st)/2;
            // TTTTFFFF
            if(check(mid,arr,m)==true )
            {
                if(check(mid+1,arr,m)==false) return mid;
                else st=mid+1;
            }
            else end=mid-1;
        }
        
        return -1;
    }
};
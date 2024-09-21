class Solution {
public:
    bool check(int day, vector<int>&arr, int m, int k)
    {
        int cnt=0;
        int continuous=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=day)
            {
                continuous++;
            }
            else continuous=0;
            
            if(continuous==k) 
            {
                cnt++;
                continuous=0;
            }
        }
        
        if(cnt>=m) return true;
        else return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int min_el=INT_MAX;
        int max_el=INT_MIN;
        
        for(auto el:arr)
        {
            min_el=min(min_el,el);
            max_el=max(max_el,el);
        }
        
        int st=min_el;
        int end=max_el;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(check(mid,arr,m,k)==true && check(mid-1,arr,m,k)==false) return mid;
            if(check(mid,arr,m,k)==false) st=mid+1;
            else end=mid-1;
        }
        
        return -1;
    }
};
class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
          int n=arr.size();
        int  st=0;
        int  end=n-1;
        int  ans=n;
        while(st<=end)
        {
            int  mid=(st+end)/2;
            if(arr[mid]==k) return mid;
            if(arr[mid]>=k) 
            {
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        
        return ans;
    }
};
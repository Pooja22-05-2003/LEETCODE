class Solution {
public:
    int findMin(vector<int>& arr) {
        int st=0;
        int end=arr.size()-1;
        int ans=INT_MAX;
        while(st<=end)
        {
            int mid=(st+end)/2;
            
           
            if(arr[mid]>=arr[st])
            {
                // left part is sorted
               ans=min(ans,arr[st]);
              st=mid+1;
            }
            else
            {
                ans=min(ans,arr[mid]);
                end=mid-1;
            }
        }
        
        return ans;
    }
    
};
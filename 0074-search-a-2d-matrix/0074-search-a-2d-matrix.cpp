class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int row=arr.size();
        int col=arr[0].size();
        
        int st=0;
        int end=row-1;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            // check whether the ans lies in the current row or not
            if(arr[mid][0]<=target && arr[mid][col-1]>=target)
            {
                int low=0;
                int high=col-1;
                
                while(low<=high)
                {
                    int m=(low+high)/2;
                    if(arr[mid][m]==target) return true;
                    else if(arr[mid][m]>target) high=m-1;
                    else low=m+1;
                }
                
                return false;
            }
            
            else if(target<arr[mid][0]) end=mid-1;
            else st=mid+1;
        }
        
        return false;
        
    }
};
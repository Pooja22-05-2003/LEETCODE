class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n=arr.size();
        int m=arr[0].size();
        int st=0;
        int end=n-1;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            // check whether the element is present in the current row or not
            if(arr[mid][0]<=target && arr[mid][m-1]>=target)
            {
                
                for(int i=0;i<m;i++) 
                {
                    if(arr[mid][i]==target) return true;
                }
                return false;
                
            }
            else if(arr[mid][0]>target) end=mid-1;
            else st=mid+1;
                
        }
        return false;
    }
};
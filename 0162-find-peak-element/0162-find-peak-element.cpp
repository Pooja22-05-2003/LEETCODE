// TC=O(logn)
// SC=O(1)
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
     
        
        if(n==1) return 0;
        //  // check if the first or the last element is the peak element or not.
        
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        
        int st=1;
        int end=arr.size()-2;
        while(st<=end)
        {
            int mid=(st+end)/2;
            
          
         
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            
            else if(arr[mid]>arr[mid-1]) st=mid+1; // here mid is present in the increasing arr element, so definitely our ans will never be present in the left half.
            else end=mid-1;
        }
        
        return -1;
    }
};
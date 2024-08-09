class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        
        int st=0;
        int end=n-1;
        
        if(n==1) return arr[0];
        if(st+1<n && arr[0]!=arr[1]) return arr[0];
        else if(end-1>=0 && arr[n-1]!=arr[n-2]) return arr[n-1];
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            bool isEven = (end-mid)%2==0; // if right part of the arr after mid is even or not.
            
            if(arr[mid] == arr[mid+1]) {
                if(isEven) {              // if the arr[mid]==arr[mid+1], then now the right part contain the odd number of elements(because we excluded the mid+1, from odd part., neglect the left part and move right to st=mid+2
                    st = mid+2;
                } else {
                    end = mid-1;
                }
            } else if(arr[mid] == arr[mid-1]) {
                if(isEven) { // whole arr length is even, so if the right part contatin the even elements, then including mid, left part contatin the odd, but excluding mid and mid-1, left part contain odd elements, so shrink the search space to left
                    end = mid-2;
                } else {
                    st = mid+1;
                }
            } else {
                return arr[mid];
            }
        }
    
    // return arr[end];
        return -1;
            
    }
};
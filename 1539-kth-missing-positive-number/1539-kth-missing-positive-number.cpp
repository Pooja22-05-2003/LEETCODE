class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int n=arr.size();
         int low=0;
         int high=n-1;
         int mid=-1;
         while(low<=high){
             mid=low+(high-low)/2;
             int x=arr[mid]-(mid+1);
             if(x<k){
             low=mid+1;
             }
             else {
                 high=mid-1;
             }
         }
       return low+k;
    }
};
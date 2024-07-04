class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int n=arr.size();
         int low=0;
         int high=n-1;
         int mid=-1;
         while(low<=high){
             // cout<<"low:"<<low<<" high:"<<high<<" mid:"<<low+(high-low)/2<<endl;
             mid=low+(high-low)/2;
             int x=arr[mid]-(mid+1);
             if(x<k){
             low=mid+1;
             }
             else {
                 high=mid-1;
             }
         }
        // cout<<"low:"<<low<<endl;
       return low+k; 
        /*
        arr = [1,2,3,4], k = 2
        
        when low=4  then  while loop will break and we need to return 2nd element after 3rd index(meand element=4 is present at the third index) return 4+2=6.
        
        */
    }
};
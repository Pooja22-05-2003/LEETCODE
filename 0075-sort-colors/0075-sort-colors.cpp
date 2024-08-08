class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=0;
        
        int k=n-1;
        
        while(j<=k)
        {
            if(arr[j]==0)
            {
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else if(arr[j]==1)
            {
                j++;
            } 
            else if(arr[j]==2)
            {
                swap(arr[j],arr[k]);
                k--;
            }  
        } 
    }
};
// Two pointer
// TC=O(n)
// SC=O(1)
class Solution {
public:
    int trap(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        
        int leftmax=INT_MIN;
        int rightmax=INT_MIN;
        
        int res=0;
        while(left<right)
        {
            if(arr[left]>=arr[right])
            {
                // water stored in the right
                if(arr[right]>=rightmax) rightmax=arr[right];
                
                else res+=(rightmax-arr[right]);
                // cout<<"right"<<(rightmax-arr[right])<<endl;
                right--;
            }
            else
            {
                // water stored in the left
                if(arr[left]>=leftmax) leftmax=arr[left];
               
                else res+=(leftmax-arr[left]);
                cout<<"left:"<<(leftmax-arr[left])<<endl;
                left++;
            }
        }
        
        return res;
    }
};
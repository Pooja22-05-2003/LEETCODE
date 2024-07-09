// TC=O(n+m)
// SC=O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        int i=0;
        int j=0;
        
        vector<int>arr;
        while(i<size1 && j<size2)
        {
            if(nums1[i]<=nums2[j])
            {
                arr.push_back(nums1[i]);
                i++;
            }
            else 
            {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<size1)
        {
            arr.push_back(nums1[i]);
            i++;
        }
        
        while(j<size2)
        {
            arr.push_back(nums2[j]);
            j++;
        }
        
        int tot=size1+size2;
        
        if(tot%2==0)
        {
            int ind1=(tot/2)-1;
            int ind2=tot/2;
            return (double(arr[ind1])+(double)arr[ind2])/2;
        }
        else
        {
            return (double)arr[tot/2];
        }
        
        return -1;
    }
};
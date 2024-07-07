class Solution {
public:
    int findnextgreater(vector<int>arr, int el, int ind)
    {
        int i=0;
        for(i=ind+1;i<arr.size();i++)
        {
            if(arr[i]>el) return i;
        }
        
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        int size1=arr1.size();
        int size2=arr2.size();
        
        vector<int>ans(size1,-1);
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<size2;i++)
        {
            mp[arr2[i]]=i;
        }
        
        for(int i=0;i<size1;i++)
        {
            int el=arr1[i];
            int ind=mp[el];
            
            int ind2=findnextgreater(arr2,el,ind);
            
            if(ind2>=ind && ind2<size2) ans[i]=arr2[ind2];
           
        }    
        
        return ans;
            
    }
};
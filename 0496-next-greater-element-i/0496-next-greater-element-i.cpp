// TC=O(size1+size2)
// SC=O(size2)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>ans(arr1.size(),-1);
        stack<int>st;
        
        // O(n+n) // O(2*size2)
        for(int i=arr2.size()-1;i>=0;i--)
        {
            if(i==arr2.size()-1) 
            {
                st.push(arr2[i]);
                mp[arr2[i]]=-1;
            }
            else
            {
              while(!st.empty() && st.top()<=arr2[i]) st.pop();
              
              if(!st.empty()) mp[arr2[i]]=st.top();
              else mp[arr2[i]]=-1;
                
              st.push(arr2[i]);
            }
        }
        
        
        // O(size1)
        for(int i=0;i<arr1.size();i++)
        {
            int a=mp[arr1[i]];
            if(a==-1){}
            else ans[i]=a;
            
        }
        
        return ans;
    }
};
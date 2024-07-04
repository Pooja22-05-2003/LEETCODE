class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       
        int n=arr.size();
        unordered_map<int,int>mp;
        
        int i=0;
        int el=1;
        int cnt=0;
        while(i<n || cnt<k)
        {
            if(i<n && arr[i]==el)
            {
                i++;
                el++;
            }
            else{
                cnt++;
                el++;
            }
            
            // cout<<"i:"<<i<<" cnt:"<<cnt<<" el:"<<el<<endl;
            if(cnt==k) return el-1;
        }
            
          return -1;  
    }
};
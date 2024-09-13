class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pre(n,0);
        
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]^arr[i];
        }
        
        int sz=queries.size();
        vector<int>res(sz);
        
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            
            if(l==0) res[i]=pre[r];
            else res[i]=pre[r]^pre[l-1];
        }
        
        return res;
    }
};
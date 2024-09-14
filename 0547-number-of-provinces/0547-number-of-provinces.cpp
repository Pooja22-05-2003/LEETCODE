class Solution {
public:
    void dfs(int st, vector<int>adj[],vector<int>&vis)
    {
        vis[st]=1;
        
        for(auto it: adj[st])
        {
            if(vis[it]==0)
            {
                dfs(it,adj,vis);
            }
                
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        int m=isConnected[0].size();
        
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) 
            {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        
        return cnt;
        
    }
};
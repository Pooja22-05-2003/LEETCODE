// DFS
// TC=O(V+2E)
// SC=O(3*V)==O(V) [DFS stack space+color+adj]
class Solution {
public:
    bool dfs(int node, vector<int>&color, int c,vector<int>adj[])
    {
        color[node]=c;
    
        
        for(auto it: adj[node])
        {
            if(color[it]==color[node]) return false;
            else if(color[it]==-1 && dfs(it,color,1-c,adj)==false) return false;
        }
        
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int>adj[m];
        for(int u=0;u<m;u++)
        {
            for(auto v: graph[u])
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        vector<int>color(m,-1); // this will behave as visited also, and initlize it with -1
        
        for(int i=0;i<m;i++)
        {
            if(color[i]==-1)  if (dfs(i,color,0,adj)==false) return false;
        }
        
        return true;
  
        
    }
};
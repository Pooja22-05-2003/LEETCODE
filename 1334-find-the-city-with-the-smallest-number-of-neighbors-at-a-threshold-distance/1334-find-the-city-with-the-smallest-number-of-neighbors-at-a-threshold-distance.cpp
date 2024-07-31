class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
   
   
            
        vector<vector<int>>grid(n,vector<int>(n,1e8));
        
        for(int i=0;i<n;i++) grid[i][i]=0;
        for(auto it: edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            grid[u][v]=w;
            grid[v][u]=w;
                
        }
        
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    grid[i][j]=min(grid[i][j], (grid[i][via]+grid[via][j]));
                }
            }
        }
        
         int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
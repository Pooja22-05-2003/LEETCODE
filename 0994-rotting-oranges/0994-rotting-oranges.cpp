class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>>dir={{0,-1},{-1,0},{0,1},{1,0}};
        
        queue<pair<int,pair<int,int>>>q; // Queue will contain all the rotten oranges
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2) q.push({0,{i,j}});
            }
        }
        
        int mintime=0;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int time=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            
            for(int i=0;i<4;i++)
            {
                int newrow=row+dir[i][0];
                int newcol=col+dir[i][1];
                
                if((newrow>=0 && newrow<n && newcol>=0 && newcol<m) && (grid[newrow][newcol]==1 && vis[newrow][newcol]==0))
                {
                    vis[newrow][newcol]=1;
                    q.push({time+1,{newrow,newcol}});
                    mintime=time+1;
                }
            }
            
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0) return -1;
            }
        }
        
        return mintime;
        
    }
};
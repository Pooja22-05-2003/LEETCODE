class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;

        pair<int,int> arr[4]={{0,-1},{-1,0},{0,1},{1,0}};
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
     
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2) 
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        
        // cout<<"size:"<<q.size()<<endl;
        
        int mintime=0;
        while(!q.empty())
        {
            auto curr=q.front();q.pop();
            int r=curr.second.first;
            int c=curr.second.second;
            int time=curr.first;
            mintime=time;
            // cout<<"mintime:"<<mintime<<endl;
            for(int i=0;i<4;i++)
            {
                int nr=r+arr[i].first;
                int nc=c+arr[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    grid[nr][nc]=2;
                    // cout<<"nr:"<<nr<<" nc:"<<nc<<endl;
                    q.push({time+1,{nr,nc}});
                }
  
            }
            
        }
         for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==1) 
                    {
                        // cout<<"i:"<<i<<" j:"<<j<<endl;
                        return -1;
                    }
                }
            }
        
        return mintime;
     
    }
};
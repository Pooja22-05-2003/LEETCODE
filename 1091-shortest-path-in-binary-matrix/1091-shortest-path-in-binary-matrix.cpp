/*
Time Complexity: O( 8*N*M ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the shortest path length}, Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.

Space Complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.

*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        if(grid[0][0]==0) pq.push({1,{0,0}});
        else return -1;

        dis[0][0]=1;

        while(!pq.empty())
        {
            auto curr=pq.top(); pq.pop();

            int cost=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;

            if(i==m-1 &&  j==n-1) return cost;
            int adjr[8]={0,-1,-1,-1,0,1,1,1};
            int adjc[8]={-1,-1,0,1,1,1,0,-1};

            for(int k=0;k<8;k++)
            {
                int nr=i+adjr[k];
                int nc=j+adjc[k];

                if(nr<0 || nr>=m || nc<0 || nc>=n)
                {
                    continue;
                }
                if(grid[nr][nc]==0) 
                {
                    if(dis[nr][nc]> (1+cost))
                    {
                         pq.push({cost+1,{nr,nc}});
                         dis[nr][nc]=cost+1;
                    }
                   
                }

            }
        }

        return -1;

    }
};
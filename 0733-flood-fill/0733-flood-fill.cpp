class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>dir={{0,-1},{-1,0},{0,1},{1,0}};
        vector<vector<int>>vis=image;
        
        vis[sr][sc]=color;
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int row=curr.first;
            int col=curr.second;
            
            for(int i=0;i<4;i++)
            {
                int adjrow=row+dir[i][0];
                int adjcol=col+dir[i][1];
                
                if(adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<m && image[sr][sc]==image[adjrow][adjcol] && vis[adjrow][adjcol]!=color)
                {
                    vis[adjrow][adjcol]=color;
                    q.push({adjrow,adjcol});
                }
            }
            
           
        }
        
        return vis;
    }
};
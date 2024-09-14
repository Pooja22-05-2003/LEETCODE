// Mark all those 'O'-->'X' if that  'O' region [region is connection of every cell] is not touched with the boundaries



class Solution {
public:
    
    void dfs(int r, int c, vector<vector<int>>&vis , vector<vector<char>>& board)
    {
        int m=board.size();
        int n=board[0].size();
        vis[r][c]=1;
        
        pair<int,int> dir[4]={{0,-1},{-1,0},{0,1},{1,0}};
        for(int i=0;i<4;i++)
        {
            int nr=r+dir[i].first;
            int nc=c+dir[i].second;
            
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && board[nr][nc]=='O')
            {
                dfs(nr,nc,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        // first row
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O' && vis[0][j]==0) dfs(0,j,vis,board);
        }
        
        // iterate last row
        if(m>1)
        {
            for(int j=0;j<m;j++)
            {
                if(board[n-1][j]=='O' && vis[n-1][j]==0) dfs(n-1,j,vis,board);
            }
        }
        
        // iterate first col
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0) dfs(i,0,vis,board);
        }
        
        if(m>1)
        {
            for(int i=0;i<n;i++)
            {
                if(board[i][m-1]=='O' && vis[i][m-1]==0) dfs(i,m-1,vis,board);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && board[i][j]=='O') board[i][j]='X';
            }
        }
        
        // return board;
    }
};
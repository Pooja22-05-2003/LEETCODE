class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& board, vector<vector<int>>&vis)
    {
        int m=board.size(); int n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return ;

        int adjr[4]={-1,0,1,0};
        int adjc[4]={0,1,0,-1};

        vis[i][j]=1; // mark visited the current cell
        for(int k=0;k<4;k++)
        {
            int r=i+adjr[k];
            int c=j+adjc[k];
            if(r<0 || r>=m || c<0 || c>=n) continue;// Here, u need to check this condition, else if without checking u will acess invalid index, it will give runtime error.
            else if (!vis[r][c] && board[r][c]==1) dfs(r,c,board,vis);
        }


    }
    int numEnclaves(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        if(n==1) 
        {
            return 0;
        }
        //iterate first row and last row boundary '0' elements
        for(int j=0;j<n;j++)
        {   
            if(board[0][j]==1 && !vis[0][j])
            {
                dfs(0,j,board,vis);
            }
        }

        if(m>1){
        for(int j=0;j<n;j++)
        {
            if(board[m-1][j]==1 && !vis[m-1][j])
            {
                dfs(m-1,j,board,vis);
            }
        }
        }

        // iterate first col boundary and its'0' elements
        for(int i=0;i<m;i++)
        {
             if(board[i][0]==1 && !vis[i][0])
            {
                dfs(i,0,board,vis);
            }
        }

        // iterate last col boundary and its'0' elements
        if(n>1){
        for(int i=0;i<m;i++)
        {
             if(board[i][n-1]==1 && !vis[i][n-1])
            {
                dfs(i,n-1,board,vis);
            }
        }
        }

        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1 && !vis[i][j]) board[i][j]=cnt++;
            }
        }

        return cnt;

    }
};
// ⭐⭐
/*
Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix, and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. Also, we are running loops for boundary elements so it will take O(N) + O(M).

Space Complexity ~ O(N x M), O(N x M) for the visited array, and auxiliary stack space takes up N x M locations at max. 


*/
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>&vis)
    {
        int m=board.size(); int n=board[0].size();
        // if(i<0 || i>=m || j<0 || j>=n) return ;

        int adjr[4]={-1,0,1,0};
        int adjc[4]={0,1,0,-1};

        vis[i][j]=1; // mark visited the current cell
        for(int k=0;k<4;k++)
        {
            int r=i+adjr[k];
            int c=j+adjc[k];
            if(r<0 || r>=m || c<0 || c>=n) continue;// Here, u need to check this condition, else if without checking u will acess invalid index, it will give runtime error.
            else if (!vis[r][c] && board[r][c]=='O') dfs(r,c,board,vis);
        }


    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        if(n==1) 
        {
            return ;
        }
        //iterate first row and last row boundary '0' elements
        for(int j=0;j<n;j++)
        {   
            if(board[0][j]=='O' && !vis[0][j])
            {
                dfs(0,j,board,vis);
            }
        }

        if(m>1){
        for(int j=0;j<n;j++)
        {
            if(board[m-1][j]=='O' && !vis[m-1][j])
            {
                dfs(m-1,j,board,vis);
            }
        }
        }

        // iterate first col boundary and its'0' elements
        for(int i=0;i<m;i++)
        {
             if(board[i][0]=='O' && !vis[i][0])
            {
                dfs(i,0,board,vis);
            }
        }

        // iterate last col boundary and its'0' elements
        if(n>1){
        for(int i=0;i<m;i++)
        {
             if(board[i][n-1]=='O' && !vis[i][n-1])
            {
                dfs(i,n-1,board,vis);
            }
        }
        }


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }

        // return board;

    }
};
//Google-6 ,  Amazon-6 , Facebook-2, Adobe-2
// TC=O(n*m*4)
// SC=O(n*m*2)+O(n*m)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int adjr[4]={-1,0,1,0};
        int adjc[4]={0,1,0,-1};
        vector<vector<int>> ans(n, vector<int>(m,INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty())
        {
            auto curr=q.front();
            int r=curr.first.first;
            int c=curr.first.second;
            int d=curr.second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int nr=r+adjr[k];
                int nc=c+adjc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(vis[nr][nc]==0 && mat[nr][nc]!=0 )
                {
                    ans[nr][nc]=(d+1);
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }
                
            }


        }

        return ans;


    }
};
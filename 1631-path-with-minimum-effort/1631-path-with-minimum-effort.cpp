class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        if(n==1 && m==1) return 0;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        
        priority_queue<vector<int> ,vector<vector<int>> , greater<vector<int>>> pq;
        
        // 0 is the dist require to reach at the source 
        pq.push({0,0,0});
        
        while(!pq.empty())
        {
            auto curr=pq.top(); pq.pop();
            int d=curr[0];
            int r=curr[1];
            int c=curr[2];
            int val=mat[r][c];
            
            int adjr[4]={-1,+1,0,0};
            int adjc[4]={0,0,-1,1};
            
            for(int i=0;i<4;i++)
            {
                int newr=r+adjr[i];
                int newc=c+adjc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    int newval=mat[newr][newc];
                    int diff=abs(val-newval);
                    int maxx=max(diff,d);
                    
                    if(dis[newr][newc]> maxx)
                    {
                        dis[newr][newc]=maxx;
                        pq.push({maxx,newr,newc});
                    }
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};
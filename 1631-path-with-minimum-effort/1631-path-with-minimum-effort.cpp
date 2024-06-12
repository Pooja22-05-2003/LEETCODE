class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>>dis(m, vector<int>(n,INT_MAX));
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});
        dis[0][0]=0;
        
        while(!pq.empty())
        {
            auto curr=pq.top(); pq.pop();
            int cost=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            
            if(i==m-1 && j==n-1) return cost;
              int adjr[4]={-1,0,1,0};
              int adjc[4]={0,1,0,-1};
            
             for(int k=0;k<4;k++)
            {
                int ar=i+adjr[k];
                int ac=j+adjc[k];
                if(ar<0 || ar>=m || ac<0 || ac>=n ) continue;
                else
                {
                    
                    int effort=abs(arr[i][j]-arr[ar][ac]);
                    int max_diff=max(cost,effort);
                    
                    if(dis[ar][ac]> max_diff)
                    {
                        pq.push({max_diff,{ar,ac}});
                        dis[ar][ac]=max_diff;
                    }
                }
             }
            
        }
        
        return (dis[n-1][m-1]==INT_MAX)?0:dis[n-1][m-1];
        
    }
};
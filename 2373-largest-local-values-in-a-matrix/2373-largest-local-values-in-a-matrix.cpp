class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();

        
        vector<vector<int>>res(n-2,vector<int>(n-2,0));
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int max_i=i+2;
                int max_j=j+2;
                
                 int max_val=INT_MIN;
                for(int p=i;p<=max_i;p++)
                {
                   
                    for(int q=j;q<=max_j;q++)
                    {
                        max_val=max(max_val,grid[p][q]);
                    }
                }
                
                res[i][j]=max_val;
            }
        }
        
        return res;
    }
};
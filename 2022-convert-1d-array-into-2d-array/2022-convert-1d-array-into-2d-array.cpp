class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>mat(m,vector<int>(n));
        if(original.size()>(m*n)) return {};
        int ind=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ind<(original.size())) mat[i][j]=original[ind++];
                else return {};
            }
        }
        
        return mat;
    }
};
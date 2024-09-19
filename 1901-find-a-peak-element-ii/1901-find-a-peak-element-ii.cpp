class Solution {
public:
    int findMax(int col, int n,vector<vector<int>>& mat)
    {
        int maxEl=INT_MIN;
        int maxrow=-1;
        
        for(int row=0;row<n;row++)
        {
            // maxEl=max(maxEl,mat[row][col]);
            if(maxEl<mat[row][col])
            {
                maxEl=mat[row][col];
                maxrow=row;
            }
        }
        
        return maxrow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int st=0;
        int end=m-1;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            int row=findMax(mid,n,mat);
            
            int left=(mid>=1)?mat[row][mid-1]:-1;
            int right=(mid<=m-2)?mat[row][mid+1]:-1;
            
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]>left) st=mid+1;
            else end=mid-1;
        }
        
        return {-1,-1};
    }
};
class Solution {
public:
    
    bool find(int i, int j,int ind,string word,vector<vector<char>>& board )
    {
        int n=board.size();
        int m=board[0].size();
        int adjr[4]={0,-1,0,1};
        int adjc[4]={-1,0,1,0};
        
        
        if(ind==word.size()) return true;
        
        char temp=board[i][j];
        board[i][j]='$'; // mark it visited
        for(int k=0;k<4;k++)
        {
            int r=i+adjr[k];
            int c=j+adjc[k];
            
            if(r>=0 && r<n && c>=0 && c<m && board[r][c]!='$')
            {
                // cout<<"i:"<<i<<" j:"<<j<<" r:"<<r<<" c:"<<c<<endl;
                if(board[r][c]==word[ind]&& find(r,c,ind+1,word,board)) return true;
            }
        }
        
         board[i][j]='$'; // it will mark it as unvisited
         board[i][j]=temp;
        
        return false;
        
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                
            {
                if(board[i][j]==word[0] && find(i,j,1,word,board))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};












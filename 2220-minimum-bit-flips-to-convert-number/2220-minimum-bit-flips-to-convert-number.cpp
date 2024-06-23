class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        
        for(int i=0;i<=30;i++)
        {
            int x=(start>>i)&1;
            int y=(goal>>i)&1;
            if(x!=y) cnt++;
        }
        
        return cnt;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cnt=k;
        int res=0;
        int n=cardPoints.size();
        int sum=0;
        int j;
        for( j=n-1;j>=0;j--)
        {
            if(k>0) sum+=cardPoints[j];
            else break;
            
            res=max(res,sum);
            k--;
        }
        
        j++;
        for(int i=0;i<cnt;i++)
        {
           sum-=cardPoints[j];
           j++;
           sum+=cardPoints[i];
           res=max(res,sum);
        }
        return res;
    }
};
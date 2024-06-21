class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int s1=g.size();
        int s2=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int i=0;
        int j=0;
        
        while(i<s1 && j<s2)
            
        {
            if(g[i]<=s[j])
            {
                cnt++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        
        return cnt;
    }
};
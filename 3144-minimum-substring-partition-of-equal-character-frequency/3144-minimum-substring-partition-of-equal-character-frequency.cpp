class Solution {
public:
   bool check(vector <int> & b){
    
    
    int c1 = 0 ; 
    for(int i=0;i<26;i++){
        if(b[i]>=1){
            if(c1==0){
            c1 = b[i];
            }
            
            if(b[i]==c1){
                
            }
            else {
                return false;
            }   
        }
    }
    
    return true;
}
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int>dp(n,1000);
        
        dp[0]=1;
        
        int i=1;
        while(i<n)
        {
            int j=i;
            vector <int> b(26,0);
            while(j>=0)
            {
                // check function runs in O(26)
                b[s[j]-'a']++;
                bool balance=check(b);
                // cout<<"i:"<<i<<"j:"<<j<<" balanced:"<<balance<<endl;
                if(balance==true )
                {
                    if(j-1>=0 && dp[j-1]!=1000) dp[i]=min(dp[i], (1+dp[j-1]));
                    else dp[i]=1;
                }
                // else break;
                // cout<<" : dp[i]=>"<<dp[i]<<endl;
                j--;
            }
            
            i++;
        }
        
        return dp[n-1];
    }
};
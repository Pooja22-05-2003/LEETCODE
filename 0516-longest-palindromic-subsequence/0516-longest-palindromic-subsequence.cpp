/*
Amazon-6, LinkedIn-5,Microsoft-3,Apple-2,Bloomberg-2,Oracle-2
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        // check for string of length =1;
        // 1 length subsequence is always pallindrome
        int i=0;
        while(i<n){
            dp[i][i]=1;
            i++;
        }


        // For string of length =2
        i=0;
   
        while(i<n-1){
            int j=i+1;
            if(s[i]!=s[j])
            {
            dp[i][j]=1;          
            }

            else {
               dp[i][j]=2;           
             }

            i++;
         }
           


           int len=3;

           while(len<=n){
               i=0;
               while(i<=(n-len))
               {
                   int j =i+len-1;
                   if(s[i]!=s[j]){
                       dp[i][j]=max(dp[i][j-1] , dp[i+1][j]);
                   }
                   else {
                      
                    dp[i][j]=dp[i+1][j-1]+2; // valid pallindrome from i+1 to j-1 and adding 2 because individual s[i] and s[j] are also pallindrome)
                   }

                   i++;
               }


               len++;
           }

           return dp[0][n-1];
        }
    
};
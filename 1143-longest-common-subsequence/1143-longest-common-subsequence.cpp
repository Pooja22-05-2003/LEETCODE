// Space Optimization // ⭐⭐Here, we need to do right shift, because in the case of recursion base case is when i<0 || j<0
// tC=O(n*m)
// SC=O(n1)+O(n2)
class Solution {
public:
 
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>prev(n2+1,0); 
        vector<int>curr(n2+1,0); //⭐⭐Here in space optimization both the array should be of size n2
        
       
        // for(int j=0;j<=n2;j++) prev[j]=0; // it means when lenght of the second string is j and length of the first string 0.
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j] , curr[j-1]);
            }
            prev=curr;
        }
    
        return prev[n2];
    }
};
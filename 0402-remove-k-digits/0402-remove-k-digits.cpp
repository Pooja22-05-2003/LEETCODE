// TC=O(n)+O(k)
// SC=O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k) return "0";
        
        stack<int>st;
        
        for(int i=0;i<num.size();i++)
        {
            while(st.size()>0 && st.top()>num[i] && k>0)
            {
                st.pop();
                k--;
            }
            
            // push only of the number is non zero, or if it is zero, then it is not preceding zero
            if(!st.empty() || num[i]!='0') st.push(num[i]);
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        string res="";
        
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return (res=="")?"0":res;
    }
};
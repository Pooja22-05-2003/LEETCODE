class Solution {
public:
    string removeKdigits(string num, int k) {
        
        // edge case
        if(num.size()==k) return "0";
        string res="";
        int n=num.size();
        stack<int>st;
        // puhs the first element in the stack
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>num[i] && k>0)
            { 
                cout<<"hi"<<endl;
                st.pop();
                k--;
            }
            
             if(st.size() > 0 || num[i] != '0') {
                st.push(num[i]); //to avoid the case when we have preceeding zeros
            }
        }
        
        // remove the preceding zeroes
        
       
        
        // creating the final ans res
        while(st.size()>0 && k>0)
        {
            
            st.pop();
            k--;
        }
            
        
        while(!st.empty())
        {
         
            res.push_back(st.top());
            st.pop();
          
        }
        
        reverse(res.begin(),res.end());
        return (res=="")?"0":res;
    }
};
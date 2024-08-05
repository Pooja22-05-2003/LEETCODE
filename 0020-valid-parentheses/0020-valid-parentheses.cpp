class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(auto it:str)
        {
            if(it=='(' || it=='[' || it=='{') st.push(it);
            else
            {
                
                if(it==')')
                {
                   if(  !st.empty() && st.top()=='(')  st.pop();
                   else return false;
                }
                
                else if(it==']' )
                {
                   if(  !st.empty() && st.top()=='[')  st.pop();
                   else return false;
                }
                
                else if(it=='}' )
                {
                   if(  !st.empty() && st.top()=='{') st.pop();
                   else return false;
                }
                
                
            }
            
        }
        
        return st.empty();
    }
};
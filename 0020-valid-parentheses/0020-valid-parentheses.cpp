class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        if(len==1) return false;
        
        stack<char>st;
        
        st.push(s[0]);
        
        int ind=1;
        while(!st.empty() || ind<len)
        {
            
            if(ind==len) return false;
            char c=s[ind];
            if(c==')')
            {
                if(st.empty()) return false;
                if(st.top()=='(') 
                {
                   
                    st.pop();
                }
                else  st.push(s[ind]);
            }
            else if(c==']')
            {
                if(st.empty()) return false;
                if(st.top()=='[') 
                {
                    
                    st.pop();
                }
                else  st.push(s[ind]);
            }
            else if(c=='}')
            {
                if(st.empty()) return false;
                if(st.top()=='{') 
                {
                    st.pop();
                }
                else  st.push(s[ind]);
            }
            
            else  st.push(s[ind]);
            
            // cout<<"ind:"<<ind<<" st.size():"<<st.size()<<endl;
            ind++;
            
        }
        
        if(st.size()==0) return true;
        else return false;
            
    }
};
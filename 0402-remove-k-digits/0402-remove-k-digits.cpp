class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string st="";
        for(int i=0;i<num.size();i++)
        {
            char el=num[i];
            
            while(st.size()>0 && st.back()>el && k>0)
            {
                st.pop_back();
                k--;
            }
            
            if(st.size()>0 || el!='0') st.push_back(el);
        }
        
        
        while(st.size()>0 && k>0) 
        {
            st.pop_back();
            k--;
        }
        
        if(st=="") return "0";
        return st;
        
    }
};
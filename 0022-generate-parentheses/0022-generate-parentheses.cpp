class Solution {
public:
    bool isValid(string s)
    {
        int count=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') count++;
             if(s[i]==')') count--;
            if(count<0) return false;
        }
        
        return (count==0)?true:false;
    }
    void solve(string s, vector<string>&res, int n)
    {
        if(s.size()==(2*n) ) {
            if(isValid(s))
            {
            res.push_back(s);
           
            }
            
          
            return;
        }
        
        solve(s+'(',res,n);
        solve(s+')',res,n);
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>res;
        solve(s,res,n);
        return res;
    }
};
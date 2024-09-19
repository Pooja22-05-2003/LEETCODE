class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;
        
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
            {
                vector<int>leftresult=diffWaysToCompute(expression.substr(0,i));
                vector<int>rightresult=diffWaysToCompute(expression.substr(i+1));
                
                for(int x:leftresult)
                {
                    for(int y:rightresult)
                    {
                        
                        if(expression[i]=='+') res.push_back(x+y);
                        if(expression[i]=='-') res.push_back(x-y);
                        if(expression[i]=='*') res.push_back(x*y);
                        
                    }
                }
            }
        }
        
        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
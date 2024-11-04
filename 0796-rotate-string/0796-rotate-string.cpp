class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=goal.size();
        for(int i=1;i<=n;i++){
            string first=s.substr(0,n-i);
            string second=s.substr(n-i,i);
            string finalstring=second+first;
            
            // cout<<"FinalString:"<<finalstring<<endl;
            if(goal==finalstring) return true;
        }
        
        return false;
    }
};
/*
abcde -> cdeab

eabcd
deabc
cdeab

*/
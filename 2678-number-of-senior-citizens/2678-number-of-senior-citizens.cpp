class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto it:details){
        string curr=it;
        int x=curr[11]-'0';
        int y=curr[12]-'0';
        
        int age=(x*10)+y;
        // cout<<"x:"<<x<<" y:"<<y<<" age:"<<age<<endl;  
        if(age>60) cnt++;
        }
        
        return cnt;
    }
};
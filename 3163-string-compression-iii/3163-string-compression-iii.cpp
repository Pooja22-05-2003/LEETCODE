class Solution {
public:
    string compressedString(string word) {
        
        int cnt=1;
        char prev=word[0];
        
        string res="";
        for(int i=1;i<word.size();i++){
            char curr=word[i];
            if(curr==prev && cnt<=8){
                
                cnt++;
                
            }
            else{
                res+=to_string(cnt);
                res+=(prev);
                prev=word[i];
                cnt=1;
                
            }
        }
        

                res+=to_string(cnt);
                res+=(prev);
        
        return res;
    }
};
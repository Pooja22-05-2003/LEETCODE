
class Solution {
public:
    bool valid(int a, int b, int c) {
        return (a > 0 && b > 0 && c > 0);
    }

    int numberOfSubstrings(string s) {
        int cnta = 0, cntb = 0, cntc = 0;
        int n = s.size();
        int res = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') cnta++;
            else if (s[j] == 'b') cntb++;
            else if (s[j] == 'c') cntc++;

            while (valid(cnta, cntb, cntc)) {
                res += (n - j); // All substrings from j to n are valid when valid(cnta, cntb, cntc) is true
                if (s[i] == 'a') cnta--;
                else if (s[i] == 'b') cntb--;
                else if (s[i] == 'c') cntc--;
                i++;
            }
        }

        return res;
    }
};
/*
class Solution {
public:
    bool valid(int a, int b,int c)
    {
        return ((a>0 && b>0) && c>0)?true:false;
    }
    int numberOfSubstrings(string s) {
        int cnta=0;
        int cntb=0;
        int cntc=0;
        int n=s.size();
        int extra=0;
        int i=0;
        int j=0;
        int res=0;
        while(j<n)
        {
             if(s[j]=='a') cnta++;
             else if(s[j]=='b') cntb++;
             else cntc++;
                while((i<j) && (valid(cnta,cntb,cntc)) )
                {
                    if(s[i]=='a') cnta--;
                    else if(s[i]=='b') cntb--;
                    else cntc--;

                    i++;
                    if(valid(cnta,cntb,cntc)==true) extra++;
                    else extra=0;
                }
            
            if((valid(cnta,cntb,cntc))) res=res+1+extra;
            j++;
        }
        
        return res;
    }
};
*/
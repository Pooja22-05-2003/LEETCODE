// TC=O(n*log(10^9))
class Solution {
public:
    bool check(int day, int m , int k , vector<int>&bloomDay)
    {
        // lets take the  k size window
        
        int win=0;
        int cnt=0;
        
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day) {
                win++;
                
                if(win==k){
                    cnt++;
                    win=0;
                }
                
                
            }
            
            else{
                win=0;
            }
            
            if(cnt>m) break;
            
            
        }
        
        // cout<<"day:"<<day<<" cnt:"<<cnt<<endl;
        if(cnt>=m) return true;
        else return false;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        // long long  flowers_needed=(m*k);
        // if(flowers_needed>n) return -1;
        
        int maxx=*max_element(bloomDay.begin(),bloomDay.end());
        // for(int day=1;day<=maxx;day++)
        // {
        //     if(check(day,m,k,bloomDay)==true) return day;
        //     // cout<<"day_inside:"<<day<<endl;
        // }
        
        int st=1;
        int end=maxx;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(mid-1==0 && check(mid,m,k,bloomDay)==true) return mid;
            if((check(mid,m,k,bloomDay)==true) && check(mid-1,m,k,bloomDay)==false) return mid;
            else if(check(mid,m,k,bloomDay)==false) st=mid+1;
            else end=mid-1;
        }
        
        return -1;
        
    }
};

/*
Edge case:
flowes_needed=m*k
if(n<flowers_needed) return -1


t=1;t<=max_el

check()

{
k size window and count the maximum bouqet i can create till the ith day of blooming.

if(Cnt>=m) return true
else return false
}




*/
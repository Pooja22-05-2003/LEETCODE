class Solution {
public:
    bool check(int maxsum, vector<int>arr, int days)
    {
        int cnt=1;
        
        int sum=0;
        
        for(auto el:arr)
        {
            sum+=el;
            if(el>maxsum) return false;
            if(sum<=maxsum){
               continue; 
            }
            else
            {
                sum=el;
                cnt++;
            }
            
            if(cnt>days) break;
        }
        
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int sum=0;
        for(auto el:arr) 
        {
            sum+=el;
        }
        
        int st=1;
        int end=sum;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(check(mid,arr,days)==true && check(mid-1,arr,days)==false) return mid;
            else if(check(mid,arr,days)==true) end=mid-1;
            else st=mid+1;
        }
        
        return -1;
    }
};
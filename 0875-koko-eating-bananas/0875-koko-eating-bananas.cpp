class Solution {
public:
    bool check(int k, vector<int>arr, int h)
    {
        int time=0;
        
        for(int i=0;i<arr.size();i++)
        {
            time+=(arr[i]%k==0)? arr[i]/k: (arr[i]/k)+1;
            if(time>h) break;
        }
        
        return (time<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_el=INT_MAX; int max_el=INT_MIN;
        
        for(auto it:piles)
        {
            min_el=min(min_el,it);
            max_el=max(max_el,it);
        }
        
        int st=1;
        int end=max_el;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(mid==1 &&  check(mid,piles,h)==true) return mid;
            if( check(mid,piles,h)==true && check(mid-1,piles,h)==false) return mid;
            else if(check(mid,piles,h)==true) end=mid-1;
            else st=mid+1;
        }
        
        return -1;
            
    }
};
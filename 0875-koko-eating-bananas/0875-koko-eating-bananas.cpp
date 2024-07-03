// Brute  Force approach
// TC=O(nlogn)
// SC=O(1)

class Solution {
public:
    bool check(vector<int>& piles, int k, int h)
    {
        // total time required , if koko is eating at the speed of k banana's per hr.
        int t=0;
        
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%k==0) t+=(piles[i]/k);
            else t+=((piles[i]/k)+1);
            if(t>h) break; // ** 1st edge case:- without this it was going in the runtime error.
         
        }
        
      
       return (t<=h)?true:false;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int max_k=*max_element(piles.begin(),piles.end());
        
        // for(int k=1;k<=max_k;k++) // ** 2nd edge case:- Don't start this with k=0, this will never lead to ans and will even give the zero divisible error.
        // {
        //     if(check(piles,k,h)==true) return k;
        // }
        
         int st=1;
         int end=max_k;
        
         while(st<=end)
         {
             int mid=(st+end)/2;
             
             if(mid-1==0 && check(piles,mid,h)==true  ) return mid; //**  Edge case:- Must need to add this case for the 1 size arr else it will give the runtime error.
             if((mid-1>=0) &&  check(piles,mid,h)==true && check(piles,mid-1,h)==false) return mid;
             
             else if (check(piles,mid,h)==false) st=mid+1;
             else end=mid-1;
             
         }
        return max_k;
    }
};
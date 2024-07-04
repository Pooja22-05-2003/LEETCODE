// TC=O(nlog(sum))
// SC=O(1)
class Solution {
public:
    bool check(int c, vector<int>wt, int days)
    {
        // cout<<"c:"<<c<<endl;
        int cnt=1;
        
        int s=0;
        for(int i=0;i<wt.size();i++)
        {
            if(c<wt[i]) return false; // ⭐⭐Edge case:-each package wt must be smaller than capacity then only we can pick that element.
            if((s+wt[i])<=c) 
            {
                s+=wt[i];
            }  
            else
            {
                cnt++;
                if(cnt>days) break;
                s=wt[i]; // ⭐⭐Here i did wrong by initializing the s with 0, but it should be initilized with that number.
            }
            
            // cout<<"i:"<<i<<" cnt:"<<cnt<<endl;
            
            
        }
        
        // if(s!=0) cnt++;
        
        
        if(cnt<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=INT_MAX;
        
        int sum=0;
        int minEl=INT_MAX;
        for(auto it: weights) sum+=it;
        
        for(int i=0;i<weights.size();i++) 
        {
            minEl=min(minEl,weights[i]);
            sum+=weights[i];
        }
        
        // for(int i=minEl;i<=sum;i++)
        // {
        //     if(check(i,weights,days)==true) return i;
        // }
        
        int st=minEl;
        int end=sum;
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(mid-1==0 && check(mid,weights,days)==true) return mid;
            if(check(mid,weights,days)==true && check(mid-1,weights,days)==false) return mid;
            if(check(mid,weights,days)==true) end=mid-1;
            else st=mid+1;
        }
        
        return sum;
    }
};
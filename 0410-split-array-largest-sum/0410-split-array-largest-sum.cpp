// O(nlog(sum))
class Solution {
public:
    bool check(int sum, vector<int>&nums, int k)
    {
        int cnt=1;
        if(nums[0]>sum) return false;//////////Edge case 1.⭐
        int s=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>sum) return false;//////////Edge case 2⭐
            if((nums[i]+s)<=sum)
            {
                s+=nums[i];
            
            }
            else
            {
                s=0;
                cnt++;
                s+=nums[i];
            }
        }
        
        // cout<<"sum:"<<sum<<" cnt:"<<cnt<<endl;
        if(cnt<=k) return true; //////////Edge case 3⭐ // I used >=k , but it is incorrect, correction condition is (cnt<=k)
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int minEl=INT_MAX;
        int maxEl=INT_MIN;
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            minEl=min(minEl,nums[i]);
            maxEl=max(maxEl,nums[i]);
            sum+=nums[i];
        }
        
        // cout<<"minEl:"<<minEl<<" maxEl:"<<maxEl<<" sum:"<<sum<<endl;
//         for(int i=minEl;i<=sum;i++)
//         {
//             // cout<<"i:"<<i<<endl;
//             bool temp=check(i,nums,k);
//             // cout<<"temp:"<<temp<<endl;
//             if(check(i,nums,k)==true) return i;

//         }
        
        
        int st=minEl;
        int end=sum; //////////Edge case 4-end range of the ans can go upto sum⭐
        
        while(st<=end)
        {
            int mid=(st+end)/2;
            
            if(mid-1==0 && check(mid,nums,k)==true) return mid;
            if(check(mid,nums,k)==true && check(mid-1,nums,k)==false) return mid;
            if(check(mid,nums,k)==false) st=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};
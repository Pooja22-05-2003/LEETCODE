class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        
        
        int cnt1=0; int cnt2=0;
        int el1=INT_MIN; int el2=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=el2)
            {
                cnt1++;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1)
            {
                cnt2++;
                el2=nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
        int count1=0; // for el1
        int count2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(el1==nums[i]) count1++;
            if(el2==nums[i]) count2++;
        }
        
        int requiredCount=(int)(n/3)+1;
        
        if(count1>=requiredCount)
        {
            res.push_back(el1);
        }
        if(count2>=requiredCount)
        {
            res.push_back(el2);
        }
        
        sort(res.begin(),res.end());
        return res;
            
    }
};
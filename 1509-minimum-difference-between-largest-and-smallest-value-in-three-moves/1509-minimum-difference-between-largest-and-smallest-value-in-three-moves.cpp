class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int k=3;
        
        if(n<=4) return 0;
        
        int ans=INT_MAX;
        
        // cout<<"1:"<<(nums[n-3-1]-nums[0])<<" 2:"<<(nums[n-1]-nums[3])<<" 3:"<<(nums[n-2-1]-nums[1])<<" 4:"<<(nums[n-1-1]-nums[2])<<endl;
        ans=min(ans,nums[n-3-1]-nums[0]); // changing  all the elements from the right side
        ans=min(ans,nums[n-1]-nums[3]);   // changing all the element from the left side
        ans=min(ans,nums[n-2-1]-nums[1]) ; // change 1 element from the left side and the other 2 element from the right side.
        
        ans=min(ans,nums[n-1-1]-nums[2]); // changing 2 element from the 1 element fromt he right side.
        return ans;
    }
};

/*
[1,5,0,10,14, 12,11,9,8,4, 1] , k=3
 0 1 2 3  4   5  6  7 8 9 10
*/
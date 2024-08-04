class Solution {
public:
    void solve(int num, int limit, int target,vector<int>&temp,vector<vector<int>>&res)
    {
        // base case
        if(target==0 && limit==0)
        {
            res.push_back(temp);
            return;
        }
        
        if(target<0) return;
        
        for( int curr=num;curr<=9;curr++)
        {
            if(target>=curr)
            {
                temp.push_back(curr);
                solve(curr+1,limit-1,target-curr,temp,res);
                temp.pop_back();
            }
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(1,k,n,temp,res);
        return res;
    }
};
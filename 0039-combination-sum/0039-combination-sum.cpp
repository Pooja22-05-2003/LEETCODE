class Solution {
public:
    void solve(int ind, vector<int>& arr , int target,  vector<int>&temp, vector<vector<int>>&res )
    {
        if(target==0){
           
            res.push_back(temp);
           
            return;
        }
        if(target<0) return;
        
        if(ind>=arr.size()) return ;
        
        // nottake
        solve(ind+1,arr,target,temp,res);
        
        //take
        if(arr[ind]<=target) 
        {
            temp.push_back(arr[ind]);
            solve(ind,arr,target-arr[ind],temp,res);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n=arr.size();
        solve(0,arr,target,temp,ans);
        
        return ans;
    }
};
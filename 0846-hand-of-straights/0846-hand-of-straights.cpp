// TC=O(nlogn)
// SC=O(n)
class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        int n=arr.size();
        if(n%k!=0) return false;
        
        map<int,int>mp;
        
        for(auto it: arr) mp[it]++; // O(nlogn)
        
        while(!mp.empty())
        {
            auto curr=mp.begin()->first; // first is the element and second is the frequency
            
            for(int i=0;i<k;i++)
            {
                if(mp[curr+i]==0) return false;
                
                mp[curr+i]--;
                if(mp[curr+i]<1) mp.erase(curr+i);
            }
        }
        
        return true;
    }
};
/*
[1,2,3,6,2,3,4,7,8]
[1,2,2,3,3,4,6,7,8]



*/
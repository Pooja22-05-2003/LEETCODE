// Approach2: Better Approach
// TC=O(n*log(n))
// SC=O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>res;
        // element,ind
        priority_queue<pair<int,int>>pq;
        
     
        
        for(int i=0;i<n;i++)
        {
            // we cannot tolerated the topmost element index out of the window {valid window size[(i-k-1).....i]}
            pq.push({nums[i],i});
            if(i>=(k-1)){
            while(!pq.empty() && pq.top().second<=(i-k)) pq.pop(); // ⭐here i missed the equal to sign in pq.top.second<=.
            
            res.push_back(pq.top().first);
            }
            
           
        }
        
        return res;
    }
};
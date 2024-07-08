// TC=O(n)
// SC=O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        // in dequeue we will push the index
        deque<int>dq; // ⭐dequeue template has name deque and not dequeue
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
          
            
            while(!dq.empty() && dq.front()<=(i-k)) dq.pop_front();
            
            // dq will maintain the elements in the decreasing order. monotonic decreasing order
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back(); //⭐Here nums[dq.back()] will come and not front
            dq.push_back(i);
            
            if(i>=k-1)
            {
              res.push_back(nums[dq.front()]);  
            }
        }
        
        return res;
    }
};
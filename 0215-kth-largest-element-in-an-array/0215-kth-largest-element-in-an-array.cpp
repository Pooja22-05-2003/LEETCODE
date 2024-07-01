// If we maintain always the size of the PQ to be of size k.
// whenever size exceed k, pop the smallest element.[maintain min-heap, it will store min element at the top.]
// Now after iterating the whole array, the kth largest element is at the top of the priority queue of k size, so return pq.top

// TC=O(N*logk)
// SC=O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            
        }
        
       while(k>1)
       {
           pq.pop();
           k--;
       }
        
        return pq.top();
    }
};


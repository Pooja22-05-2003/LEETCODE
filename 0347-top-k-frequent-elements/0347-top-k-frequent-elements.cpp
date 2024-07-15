// TC=O(n)+O(klogk)
// SC=O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

         unordered_map<int,int>mp;
            vector<int>ans;
        for(auto it: nums) mp[it]++;

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto it: mp)
        {
            int el=it.first;
            int freq=it.second;

            pq.push({freq,el});

            if(pq.size()>k) pq.pop();
            
           
        }

        // while(!pq.empty() && pq.size()>k) pq.pop();

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        
        return ans;
        
    }
};
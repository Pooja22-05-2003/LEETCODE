class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        
        vector<pair<int,pair<int,int>>>v;  // first [{end_time,{ind,start_time}}]
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back({arr[i][1],{i,arr[i][0]}});
        }
        
        sort(v.begin(),v.end());
      
        int cnt=1;
        int prev=v[0].first;
        for(int i=1;i<v.size();i++){
            if(v[i].second.second >= prev){
                cnt++;
                prev=v[i].first;
            }
        }
        
        return n-cnt;// Just single change from the n meeting in 1 room
    }
};
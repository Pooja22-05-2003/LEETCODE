class Twitter {
public:
    
    // Creating 1 data structure which keep track of userID and all its follower, as all the followers have their unique ID, so we can use unordered_set
    
    // {mp[userID]-> {All the ID of the people which the current user folllwed}}
    map<int,unordered_set<int>>mp;
    
    
    // Priority queue, will keep track of all the tweets in the sorted order of their timing.
    // {time,TwitID, userID}
    priority_queue<vector<int>>pq;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
         time++;
        pq.push({time,tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
       
        // first copy the PQ, so that the original will not get affected
         priority_queue<vector<int>>pq1=pq;
         vector<int>res;
         int cnt=0;
        
         while(!pq1.empty() && cnt<10)
         {
             auto curr=pq1.top();
             int currUserID=curr[2];
              pq1.pop();
             if(userId==currUserID || mp[userId].count(currUserID)!=0)
             {
                 res.push_back(curr[1]);
                
                 cnt++;
             }
         }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
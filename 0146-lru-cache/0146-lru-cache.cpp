// dll mei erase back se karenge, and most recently ko front mei rakhenge
class LRUCache {
public:
    int n;
    list<int>dll;
    // mp=> {key->{address,value}}
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    LRUCache(int cap) {
        n=cap;
    }
    
    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            makeRecentlyUsed(key);
            int ans=mp[key].second;
            return ans;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
           makeRecentlyUsed(key);
            mp[key].second=value;
        }
        else
        {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        
        while(n<0)
        {
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
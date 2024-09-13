class LRUCache {
public:
    int size;
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
        
    LRUCache(int capacity) {
        size=capacity;
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
            return mp[key].second;
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
            mp[key].second=value;
            dll.push_front(key);
            mp[key].first=dll.begin();
            size--;
        }
        
        
        while(size<0)
        {
            mp.erase(dll.back());
            dll.pop_back();
            
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
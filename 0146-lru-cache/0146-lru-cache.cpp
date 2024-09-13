class LRUCache {
public:
    int size;
    list<int>dll;
    
    // {key->{address,value}}
    unordered_map<int,pair<list<int>::iterator,int>  >mp;
    
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
        else return -1;
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

// TC=O(n)
// SC=O(n)
class LRUCache {
public:
     list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp; // this map will store the key->address and the value
    int n;
    LRUCache(int capacity) {
        n=capacity;
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
            mp[key].second=value;
            makeRecentlyUsed(key);
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
146. LRU Cache 
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Hide Company Tags Google Uber Facebook Twitter Zenefits Amazon Microsoft Snapchat Yahoo Bloomberg Palantir
Hide Tags Design

class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node(int k, int v): key(k), val(v) {}
    };
    
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end()) return -1;
        if (mp[key]!=data.begin()) {
            data.erase(mp[key]);
            data.push_front(*mp[key]);
            mp[key]=data.begin();
        }
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()) {
            if (mp[key]!=data.begin()) {
                data.erase(mp[key]);
                data.push_front(*mp[key]);
                mp[key]=data.begin();
            }
            mp[key]->val=value;
        } else {
            if (mp.size()==capacity) {
                int k=data.back().key;
                data.pop_back();
                mp.erase(k);
            }
            Node n(key, value);
            data.push_front(n);
            mp[key]=data.begin();
        }
    }
private:
    int capacity;
    list<Node> data;
    unordered_map<int,list<Node>::iterator> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


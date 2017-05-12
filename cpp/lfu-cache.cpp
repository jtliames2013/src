460. LFU Cache Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 9676
Total Submissions: 42765
Difficulty: Hard
Contributors:
1337c0d3r  ,
fishercoder
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
Subscribe to see which companies asked this question.

Hide Tags Design
Hide Similar Problems (H) LRU Cache

class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        minCount=0;
    }
    
    int get(int key) {
        if (data.find(key)==data.end()) return -1;
        int cnt=data[key].second++;
        keys[cnt+1].push_front(key);
        keys[cnt].erase(keyIter[key]);
        keyIter[key]=keys[cnt+1].begin();
        if (keys[cnt].empty()) {
            keys.erase(cnt);
            if (minCount==cnt) minCount++;
        }
        return data[key].first;
    }
    
    void put(int key, int value) {
        if (capacity<=0) return;
        int val=get(key);
        if (val!=-1) {
            data[key].first=value;
            return;
        }
        if (data.size()>=capacity) {
            int k=keys[minCount].back();
            keys[minCount].pop_back();
            keyIter.erase(k);
            data.erase(k);
        }
        data[key]={value,1};
        keys[1].push_front(key);
        keyIter[key]=keys[1].begin();
        minCount=1;
    }
private:
    int capacity;
    int minCount;
    unordered_map<int,pair<int,int>> data; // value, count
    unordered_map<int,list<int>> keys; // count, list of keys
    unordered_map<int,list<int>::iterator> keyIter; // key, key iterator in the list
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


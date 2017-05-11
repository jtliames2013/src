432. All O`one Data Structure Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 5074
Total Submissions: 18505
Difficulty: Hard
Contributors:
galster  ,
1337c0d3r
Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.

Subscribe to see which companies asked this question.

Hide Tags Design

The main idea is to maintain an ordered two-dimensional doubly-linked list (let's call it matrix for convenience), of which each row is corresponding to a value and all of the keys in the same row have the same value.

Suppose we get the following key-value pairs after some increment operations. ("A": 4 means "A" is increased four times so its value is 4, and so on.)

"A": 4, "B": 4, "C": 2, "D": 1
Then one possible matrix may look like this:

row0: val = 4, strs = {"A", "B"}
row1: val = 2, strs = {"C"}
row2: val = 1, strs = {"D"}
If we can guarantee the rows are in descending order in terms of value, then GetMaxKey()/GetMinKey() will be easy to implement in O(1) time complexity. Because the first key in the first row will always has the maximal value, and the first key in the last row will always has the minimal value.

Once a key is increased, we move the key from current row to last row if last_row.val = current_row.val + 1. Otherwise, we insert a new row before current row with vallue current_row.val + 1, and move the key to to the new row. The logic of decrement operation is similar. Obviously, by doing this, the rows will keep its descending order.

For example, after Inc("D"), the matrix will become

row0: val = 4, strs = {"A", "B"}
row1: val = 2, strs = {"C", "D"}
Inc("D") again

row0: val = 4, strs = {"A", "B"}
row1: val = 3, strs = {"D"}
row2: val = 2, strs = {"C"}
Now the key problem is how to maintain the matrix in O(1) runtime when increase/decrease a key by 1.

The answer is hash map. By using a hash map to track the position of a key in the matrix, we can access a key in the matrix in O(1). And since we use linked list to store the matrix, thus insert/move operations will all be O(1).

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (mp.find(key)==mp.end()) {
            if (l.empty() || l.back().count>1) {
                l.push_back(Node(1));
            }
            l.back().keys.insert(key);
            mp[key]=--(l.end());
        } else {
            auto iter=mp[key], prev=iter;
            prev--;
            int cnt=iter->count;
            if (iter==l.begin() || prev->count>cnt+1) {
                prev=l.insert(iter, Node(cnt+1));
            }
            prev->keys.insert(key);
            mp[key]=prev;
            
            iter->keys.erase(key);
            if (iter->keys.empty()) l.erase(iter);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (mp.find(key)==mp.end()) return;
        auto iter=mp[key], next=iter;
        next++;
        int cnt=iter->count;
        if (cnt>1) {
            if (next==l.end() || next->count<cnt-1) {
                next=l.insert(next, Node(cnt-1));
            }
            next->keys.insert(key);
            mp[key]=next;
        } else {
            mp.erase(key);
        }
        
        iter->keys.erase(key);
        if (iter->keys.empty()) l.erase(iter);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (l.empty()) return "";
        return *(l.front().keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (l.empty()) return "";
        return *(l.back().keys.begin());
    }
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node(int c): count(c) {}
    };

    list<Node> l;
    unordered_map<string, list<Node>::iterator> mp;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */


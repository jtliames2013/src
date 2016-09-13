class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int res=false;
        if (table.find(val)==table.end() || table[val].empty()) {
            res=true;
        }
        data.push_back(val);
        table[val].insert(data.size()-1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter=table.find(val);
        if (iter==table.end() || table[val].empty()) return false;
        int index=data.size()-1;
        int last=data[index];
        data.pop_back();
        table[last].erase(index);
        if (val!=last) {
            int rmIdx=*(table[val].begin());
            table[val].erase(table[val].begin());
            data[rmIdx]=last;
            table[last].insert(rmIdx);
        } 
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (data.size()>0) {
            return data[rand()%data.size()];
        } else {
            return -1;
        }
    }
private:
    unordered_map<int,set<int>> table;
    vector<int> data;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

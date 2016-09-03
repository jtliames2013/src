380. Insert Delete GetRandom O(1)  QuestionEditorial Solution  My Submissions
Total Accepted: 1014 Total Submissions: 3013 Difficulty: Medium
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
Hide Company Tags Google Uber Twitter Amazon Yelp Pocket Gems
Hide Tags Array Hash Table Design

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto iter=table.find(val);
        if (iter==table.end()) {
            data.push_back(val);
            table[val]=data.size()-1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter=table.find(val);
        if (iter!=table.end()) {
            int lastVal=data[data.size()-1];
            int lastIdx=iter->second;
            if (iter->second!=data.size()-1) {
                swap(data[iter->second], data[data.size()-1]);
                table[lastVal]=lastIdx;
            }
            data.pop_back();
            table.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (data.size()>0) {
            int num=rand()%data.size();
            return data[num];
        } else {
            return -1;
        }
    }
private:
    vector<int> data;
    unordered_map<int,int> table;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


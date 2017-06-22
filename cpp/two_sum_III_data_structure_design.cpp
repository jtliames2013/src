170. Two Sum III - Data structure design
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        mp[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto iter:mp) {
            int n=value-iter.first;
            if (mp.find(n)!=mp.end() && (n!=iter.first || mp[n]>1)) return true;
        }
        return false;
    }
private:
    unordered_map<int,int> mp;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */


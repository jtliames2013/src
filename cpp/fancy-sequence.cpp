1622. Fancy Sequence
Hard

132

31

Add to List

Share
Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

Fancy() Initializes the object with an empty sequence.
void append(val) Appends an integer val to the end of the sequence.
void addAll(inc) Increments all existing values in the sequence by an integer inc.
void multAll(m) Multiplies all existing values in the sequence by an integer m.
int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
 

Example 1:

Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
 

Constraints:

1 <= val, inc, m <= 100
0 <= idx <= 105
At most 105 calls total will be made to append, addAll, multAll, and getIndex.

class Fancy {
public:
    Fancy() {
        add.push_back(0);
        mul.push_back(1);
    }

    void append(int val) {
        nums.push_back(val);
        add.push_back(add.back());
        mul.push_back(mul.back());
    }

    void addAll(int inc) {
        add.back()+=inc;
    }

    void multAll(int m) {
        add.back()=add.back()*m%mod;
        mul.back()=mul.back()*m%mod;
    }

    int getIndex(int idx) {
        if (idx>=nums.size()) return -1;
        long m=mul.back()*powMod(mul[idx], mod-2)%mod;
        return ((nums[idx]-add[idx]+mod)*m+add.back())%mod;
    }
private:
    vector<long> nums;
    vector<long> add;
    vector<long> mul;
    const int mod=1e9+7;

    long powMod(int n, int p) {
        if (p==1) return n;
        long half=powMod(n, p/2);
        return (half * half % mod * (p%2==1?n:1))%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */


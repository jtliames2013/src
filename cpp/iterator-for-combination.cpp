5123. Iterator for Combination
Medium

12

1

Favorite

Share
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.

Google
|
LeetCode

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        this->characters=characters;
        n=characters.size();
        len=combinationLength;
        index.resize(len);
        for (int i=0; i<len; ++i) index[i]=i;
        pos=len-1;
        tryAdvance();
    }
    
    string next() {
        if (!hasNext()) return "";
        string res;
        for (int i=0; i<len; ++i) res+=characters[index[i]];
        index[pos]++;
        tryAdvance();
        return res;
    }
    
    bool hasNext() {
        return pos>=0;
    }
private:
    void tryAdvance() {
        if (pos<0 || index[pos]<=pos+n-len) return;
        pos--;
        while (pos>=0 && index[pos]==pos+n-len) pos--;
        if (pos<0) return;
        index[pos]++;
        for (int i=pos+1; i<len; ++i) index[i]=index[i-1]+1;
        pos=len-1;
    }
    
    string characters;
    int n;
    vector<int> index;
    int len;
    int pos; 
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


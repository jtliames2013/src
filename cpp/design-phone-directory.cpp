379. Design Phone Directory  QuestionEditorial Solution  My Submissions
Total Accepted: 700 Total Submissions: 2732 Difficulty: Medium
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
Hide Company Tags Google
Hide Tags Linked List Design

Dropbox
|
9

Google
|
4

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers=maxNumbers;
        for (int i=0; i<maxNumbers; i++) available.push_back(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (available.empty()) return -1;
        int res=available.front();
        available.pop_front();
        used.insert(res);
        
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number>=0 && number<maxNumbers && used.find(number)==used.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used.find(number)!=used.end()) {
            used.erase(number);
            available.push_back(number);
        }
    }
private:
    int maxNumbers;
    list<int> available;
    unordered_set<int> used;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */


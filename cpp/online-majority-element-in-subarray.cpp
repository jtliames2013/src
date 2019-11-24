1157. Online Majority Element In Subarray
Hard

112

16

Favorite

Share
Implementing the class MajorityChecker, which has the following API:

MajorityChecker(int[] arr) constructs an instance of MajorityChecker with the given array arr;
int query(int left, int right, int threshold) has arguments such that:
0 <= left <= right < arr.length representing a subarray of arr;
2 * threshold > right - left + 1, ie. the threshold is always a strict majority of the length of the subarray
Each query(...) returns the element in arr[left], arr[left+1], ..., arr[right] that occurs at least threshold times, or -1 if no such element exists.

 

Example:

MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // returns 1
majorityChecker.query(0,3,3); // returns -1
majorityChecker.query(2,3,2); // returns 2
 

Constraints:

1 <= arr.length <= 20000
1 <= arr[i] <= 20000
For each query, 0 <= left <= right < len(arr)
For each query, 2 * threshold > right - left + 1
The number of queries is at most 10000

As the majority occurs more than half in the interval [l, r], we will have the probability of more than 1/2 to find 
the "more than half" majority if we randomly pick a number in the interval. Thus, if we randomly pick try_bound times, 
we will have the probability of (1-(1/2)) ** try_bound not to find the "more than half" majority. The probability 
will be less than 1e-6 if we set try_bound as 20. If we find nothing in try_bound times, we can claim that there is 
no "more than half" majority.

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        this->arr=arr;
        for (int i=0; i<arr.size(); ++i) mp[arr[i]].push_back(i);
        maxTry=20;
    }
    
    int query(int left, int right, int threshold) {
        for (int i=0; i<maxTry; ++i) {
            int num=arr[left+rand()%(right-left+1)];
            if (getCount(num, left, right)>=threshold) return num;
        }
        return -1;
    }    
private:
    int getCount(int num, int left, int right) {
        if (mp.find(num)==mp.end()) return 0;
        auto lower=lower_bound(mp[num].begin(), mp[num].end(), left);
        if (lower==mp[num].end()) return 0;
        auto upper=upper_bound(mp[num].begin(), mp[num].end(), right);
        return upper-lower;
    }
    
    vector<int> arr;
    unordered_map<int, vector<int>> mp;
    int maxTry;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */


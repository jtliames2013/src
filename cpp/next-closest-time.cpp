681. Next Closest Time
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

Google
|
2

Facebook
|
3

Uber
|
2

class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> digits;
        for (int i=0; i<time.size(); ++i) {
            if (time[i]!=':') digits.push_back(time[i]);
        }
        vector<char> curr=digits, next=digits;
        vector<char> limit={'2', curr[0]=='2'?'3':'9', '5', '9'};
        
        sort(digits.begin(), digits.end());
        for (int i=digits.size()-1; i>=0; --i) {
            next[i]=getNext(digits, curr[i], limit[i]);
            if (next[i]>curr[i]) return convert(next);
        }
        return convert(next);
    }
private:
    char getNext(vector<char> digits, char curr, char limit) {
        for (auto d:digits) {
            if (d>curr && d<=limit) return d;
        }
        return digits[0];
    }
    
    string convert(vector<char>& v) {
        string res;
        res+=v[0];
        res+=v[1];
        res+=":";
        res+=v[2];
        res+=v[3];
        return res;
    }
};


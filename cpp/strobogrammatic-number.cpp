246. Strobogrammatic Number
Easy

157

382

Favorite

Share
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false

Facebook
|
4

Google
|
2

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n=num.size(), l=0, r=n-1;
        while (l<=r) {
            if (mp.find(num[l])==mp.end() || mp[num[l]]!=num[r]) return false;
            l++;
            r--;
        }
        return true;
    }
private:
    unordered_map<char,char> mp={{'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'}};
};


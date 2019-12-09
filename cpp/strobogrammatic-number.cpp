246. Strobogrammatic Number
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mp={{'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'}};
        int n=num.size(), l=0, r=n-1;
        while (l<=r) {
            if (mp.find(num[l])==mp.end() || mp[num[l]]!=num[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};


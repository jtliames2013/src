266. Palindrome Permutation
Easy

262

43

Favorite

Share
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

Facebook
|
3

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> mp;
        for (auto c:s) mp[c]++;
        int odd=0;
        for (auto& iter:mp) {
            if (iter.second%2==1) {
                odd++;
                if (odd>1) return false;
            }
        }
        return true;
    }
};


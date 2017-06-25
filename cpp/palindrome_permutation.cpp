266. Palindrome Permutation
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
Hide Company Tags Google Uber
Hide Tags Hash Table
Hide Similar Problems (M) Longest Palindromic Substring (E) Valid Anagram (M) Palindrome Permutation II

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> mp;
        for (auto c:s) mp[c]++;
        int odd=0;
        for (auto& iter:mp) {
            if (iter.second%2==1) odd++;
            if (odd>1) return false;
        }
        return true;
    }
};


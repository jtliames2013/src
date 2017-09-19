242. Valid Anagram  QuestionEditorial Solution  My Submissions
Total Accepted: 101332 Total Submissions: 233643 Difficulty: Easy
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Hide Company Tags Amazon Uber Yelp
Hide Tags Hash Table Sort
Hide Similar Problems (M) Group Anagrams (E) Palindrome Permutation

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unordered_map<char,int> mp;
        for (auto c:s) mp[c]++;
        for (auto c:t) {
            mp[c]--;
            if (mp[c]<0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;
        for (auto c:s) count[c]++;
        for (auto c:t) count[c]--;
        for (auto cnt:count) {
            if (cnt.second!=0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);
        for (auto c:s) count[c-'a']++;
        for (auto c:t) count[c-'a']--;
        for (auto cnt:count) {
            if (cnt!=0) return false;
        }
        return true;
    }
};


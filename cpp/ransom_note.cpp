383. Ransom Note   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 33479
Total Submissions: 73082
Difficulty: Easy
Contributors: Admin
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
Subscribe to see which companies asked this question

Hide Tags String
    
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> mp;
        for (auto l:magazine) mp[l]++;
        for (auto l:ransomNote) {
            if (mp.find(l)==mp.end()||mp[l]==0) return false;
            mp[l]--;
        }
        return true;
    }
};

2. Use array
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(256);
        for (auto l:magazine) mp[l]++;
        for (auto l:ransomNote) {
            if (mp[l]==0) return false;
            mp[l]--;
        }
        return true;
    }
};


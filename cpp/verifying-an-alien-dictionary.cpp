953. Verifying an Alien Dictionary
Easy

85

30

Favorite

Share
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Note:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are english lowercase letters.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        mp['\0']=-1;
        for (int i=0; i<order.size(); ++i) mp[order[i]]=i;
        for (int i=1; i<words.size(); ++i) {
            for (int j=0; j<=words[i].size() && j<=words[i-1].size(); ++j) {
                if (mp[words[i][j]]<mp[words[i-1][j]]) return false;
                else if (mp[words[i][j]]>mp[words[i-1][j]]) break;
            }            
        }
        
        return true;
    }
};

2.
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;        
        for (int i=0; i<order.size(); ++i) mp[order[i]]=i;
        for (auto &w:words) {
            for (auto &c:w) c=mp[c];
        }
        
        return is_sorted(words.begin(), words.end());
    }
};


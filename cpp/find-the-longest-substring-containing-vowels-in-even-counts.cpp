1371. Find the Longest Substring Containing Vowels in Even Counts
Medium

83

2

Add to List

Share
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res=0, n=s.size(), state=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for (int i=0; i<n; ++i) {
            if (vowels.find(s[i])!=vowels.end()) {
                state ^= (1<<vowels[s[i]]);
                if (mp.find(state)==mp.end()) mp[state]=i;
            }
            res=max(res, i-mp[state]);
        }
        return res;
    }
private:
    unordered_map<char, int> vowels={{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
};


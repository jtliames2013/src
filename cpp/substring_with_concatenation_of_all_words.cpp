30. Substring with Concatenation of All Words
DescriptionHintsSubmissionsSolutions
Total Accepted: 78243
Total Submissions: 358481
Difficulty: Hard
Contributor: LeetCode
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Subscribe to see which companies asked this question.

Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Minimum Window Substring

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n=words.size();
        if (n==0) return res;
        int l=words[0].size(), size=s.size();
        unordered_map<string,int> m;
        for (auto& w:words) m[w]++;
        
        for (int i=0; i<=size-n*l; i++) {
            unordered_map<string,int> mp=m;
            int j;
            for (j=0; j<n; j++) {
                string w=s.substr(i+j*l, l);
                if (mp.find(w)==mp.end()) break;
                mp[w]--;
                if (mp[w]==0) mp.erase(w);
            }
            if (j==n) res.push_back(i);
        }
        return res;
    }
};


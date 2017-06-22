243. Shortest Word Distance
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res=INT_MAX, i1=-1, i2=-1, n=words.size();
        for (int i=0; i<n; i++) {
            if (words[i]==word1) i1=i;
            else if(words[i]==word2) i2=i;
            if (i1!=-1 && i2!=-1) res=min(res, abs(i1-i2));
        }
        return res;
    }
};


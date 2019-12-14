245. Shortest Word Distance III
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.

NOTE: consider word1==word2 or not separately.

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res=INT_MAX, i1=-1, i2=-1;
        bool same=word1==word2;
        for (int i=0; i<words.size(); i++) {
            if (words[i]==word1) {
                i1=i;
                if (same) swap(i1, i2); // i2=curr, i1=prev
            } else if (words[i]==word2) {
                i2=i;
            }
            if (i1!=-1 && i2!=-1) res=min(res, abs(i1-i2));
        }
        
        return res;
    }
};


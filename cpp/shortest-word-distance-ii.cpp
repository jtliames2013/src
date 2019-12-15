244. Shortest Word Distance II
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

LinkedIn
|
21

Amazon
|
2

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i=0; i<words.size(); i++) {
            pos[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res=INT_MAX;
        int i1=0, i2=0;
        while (i1<pos[word1].size() && i2<pos[word2].size()) {
            res=min(res, abs(pos[word1][i1]-pos[word2][i2]));
            if (pos[word1][i1]<pos[word2][i2]) i1++;
            else i2++;
        }
        return res;
    }
private:
    unordered_map<string, vector<int>> pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */


737. Sentence Similarity II
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].

Google
|
3

Amazon
|
2

Bloomberg
|
2

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        int n1=words1.size(), n2=words2.size();
        if (n1!=n2) return false;
        
        unordered_map<string, string> root;
        for (auto& p:pairs) {
            string p1=find(root, p[0]);
            string p2=find(root, p[1]);
            if (p1!=p2) root[p1]=p2;
        }
        
        for (int i=0; i<n1; ++i) {
            if (words1[i]==words2[i]) continue;
            if (find(root, words1[i])!=find(root, words2[i])) return false;
        }
        return true;
    }
private:
    string find(unordered_map<string, string>& root, string s) {
        if (root.find(s)==root.end()) root[s]=s;
        while (root[s]!=s) s=root[s];
        return s;
    }
};


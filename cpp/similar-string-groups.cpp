839. Similar String Groups
Hard

216

75

Favorite

Share
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

Example 1:

Input: ["tars","rats","arts","star"]
Output: 2
Note:

A.length <= 2000
A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n=A.size(), count=n;
        vector<int> root(n);
        for (int i=0; i<n; ++i) root[i]=i;
        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (connect(A[i], A[j])) {
                    int r1=find(root, i), r2=find(root, j);
                    if (r1!=r2) {
                        root[r1]=r2;
                        count--;
                    }
                }
            }
        }
        return count;
    }
private:
    bool connect(string& a, string &b) {
        int i=0, count=0;
        for (; i<a.size() && count<=2; ++i) {
            if (a[i]!=b[i]) count++;
        }
        return count<=2;
    }
    
    int find(vector<int>& root, int i) {
        while (i!=root[i]) i=root[i];
        return i;
    }        
};


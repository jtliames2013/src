854. K-Similar Strings
DescriptionHintsSubmissionsDiscussSolution
Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.

Given two anagrams A and B, return the smallest K for which A and B are K-similar.

Example 1:

Input: A = "ab", B = "ba"
Output: 1
Example 2:

Input: A = "abc", B = "bca"
Output: 2
Example 3:

Input: A = "abac", B = "baca"
Output: 2
Example 4:

Input: A = "aabc", B = "abca"
Output: 2
Note:

1 <= A.length == B.length <= 20
A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

class Solution {
public:
    int kSimilarity(string A, string B) {
        if (A==B) return 0;
        int res=0, n=A.size();
        queue<string> q;
        unordered_set<string> visited;
        q.push(A);
        visited.insert(A);
        
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
                
                int j=0;
                while (j<n && f[j]==B[j]) j++;
                for (int k=j+1; k<n; ++k) {
                    if (f[k]==B[k] || f[k]!=B[j]) continue;
                    string next=f;
                    swap(next[j], next[k]);
                    if (next==B) return res+1;
                    if (visited.find(next)==visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }

            res++;
        }
        return -1;
    }
};


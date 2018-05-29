821. Shortest Distance to a Character
DescriptionHintsSubmissionsDiscussSolution
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.

1.
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n=S.size();
        vector<int> res(n, n);
        int pos=-n;
        for (int i=0; i<n; ++i) {
            if (S[i]==C) pos=i;
            res[i]=min(res[i], i-pos);
        }
        pos=2*n;
        for (int i=n-1; i>=0; --i) {
            if (S[i]==C) pos=i;
            res[i]=min(res[i], pos-i);
        }
        return res;
    }
};

2.
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n=S.size();
        vector<int> res(n, n);
        for (int i=0; i<n; ++i) {
            if (S[i]==C) res[i]=0;
        }
        for (int i=1; i<n; ++i) {
            res[i]=min(res[i], res[i-1]+1);
        }        
        for (int i=n-2; i>=0; --i) {
            res[i]=min(res[i], res[i+1]+1);
        }
        return res;
    }
};

28. Implement strStr()  
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Hide Company Tags Pocket Gems Microsoft Apple Facebook
Hide Tags Two Pointers String
Hide Similar Problems (H) Shortest Palindrome

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(), n=needle.size();
        for (int i=0; i<=m-n; i++) {
            int j=0;
            for (; j<n; j++) {
                if (haystack[i+j]!=needle[j]) break;
            }
            if (j==n) return i;
        }
        return -1;
    }
};


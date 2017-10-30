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

2. KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(), n=needle.size();
        if (n==0) return 0;
        vector<int> prefix(n);
        for (int k=0, q=1; q<n; q++) {
            while (k>0 && needle[k]!=needle[q]) k=prefix[k-1];
            if (needle[k]==needle[q]) k++;
            prefix[q]=k;
        }
        
        for (int i=0, j=0; i<m; i++) {
            while (j>0 && needle[j]!=haystack[i]) j=prefix[j-1];
            if (needle[j]==haystack[i]) j++;
            if (j==n) return i-n+1;
        }
        return -1;
    }
};

686. Repeated String Match
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m=A.size(), n=B.size();
        for (int i=0; i<m; i++) {
            int j=0;
            for (; j<n; j++) {
                if (B[j]!=A[(i+j)%m]) break;
            }
            if (j==n) return (i+j)/m+((i+j)%m==0?0:1);
        }
        return -1;
    }
};

2. KMP
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m=A.size(), n=B.size();
        vector<int> prefix(n+1);
        for (int q=1, k=0; q<n; q++) {            
            if (B[k]!=B[q]) k=prefix[k];
            else k++;
            prefix[q]=k;
        }
        for (int i=0, j=0; i<m; i+=max(1, j-prefix[j]), j=prefix[j]) {            
            while (j<n && A[(i+j)%m]==B[j]) j++;
            if (j==n) return (i+j)/m+((i+j)%m==0?0:1);
        }
        return -1;
    }
};


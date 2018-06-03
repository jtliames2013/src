844. Backspace String Compare
DescriptionHintsSubmissionsDiscussSolution
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

 

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
 

Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.

1.
class Solution {
public:
    string back(string s) {
        string res;
        for (auto c:s) {
            if (c!='#') res+=c;
            else if (!res.empty()) res.pop_back();
        }
        return res;
    }
    
    bool backspaceCompare(string S, string T) {
        return back(S)==back(T);
    }
};

2.
class Solution {
public:    
    bool backspaceCompare(string S, string T) {
        int m=S.size(), n=T.size();
        for (int i=m-1, j=n-1; ; --i, --j) {
            for (int b=0; i>=0 && (S[i]=='#' || b>0); --i) b+=S[i]=='#'?1:-1;
            for (int b=0; j>=0 && (T[j]=='#' || b>0); --j) b+=T[j]=='#'?1:-1;
            if (i>=0 && j>=0) {
                if (S[i]!=T[j]) return false;
            } else {
                return i==-1 && j==-1;
            }
        }
    }
};

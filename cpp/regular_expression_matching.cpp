10. Regular Expression Matching  QuestionEditorial Solution  My Submissions
Total Accepted: 86845
Total Submissions: 387248
Difficulty: Hard
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
Hide Company Tags Google Uber Airbnb Facebook Twitter
Hide Tags Dynamic Programming Backtracking String
Hide Similar Problems (H) Wildcard Matching

http://articles.leetcode.com/regular-expression-matching
* If the next character of p is NOT ‘*’, then it must match the current character of s. Continue pattern matching with the next character of both s and p.
* If the next character of p is ‘*’, then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p… Until we could not match any more characters.

bool isMatch(const char *s, const char *p) {
  assert(s && p);
  if (*p == '\0') return *s == '\0';
 
  // next char is not '*': must match current character
  if (*(p+1) != '*') {
    assert(*p != '*');
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  // next char is '*'
  while ((*p == *s) || (*p == '.' && *s != '\0')) {
    if (isMatch(s, p+2)) return true;
    s++;
  }
  return isMatch(s, p+2);
}

2. The same as before but in C++
需要用递归Recursion来解，大概思路如下：

- 若p为空，若s也为空，返回true，反之返回false

- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false

- 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配

- 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母

- 返回调用递归函数匹配s和去掉前两个字符的p的结果

class Solution {

public:

    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
   
    bool isMatch(string& s, int sIdx, string& p, int pIdx) {
      if (pIdx == p.size()) return sIdx == s.size();
      // next char is not '*': must match current character
      if (p[pIdx+1] != '*') {
        return ((p[pIdx] == s[sIdx]) || (p[pIdx] == '.' && s[sIdx] != '\0')) && isMatch(s, sIdx+1, p, pIdx+1);
      }
     
      // next char is '*'
      while ((p[pIdx] == s[sIdx]) || (p[pIdx] == '.' && s[sIdx] != '\0')) {
        if (isMatch(s, sIdx, p, pIdx+2)) return true;
        sIdx++;
      }
      return isMatch(s, sIdx, p, pIdx+2);
    }
};

class Solution {
public:
    bool isMatch(string& s, int i, string& p, int j) {
        if (j==p.size()) {
            return i==s.size();
        } else {
            if (p[j+1]!='*') {
                return (((p[j]=='.' &&  s[i]!='\0') || s[i]==p[j]) && isMatch(s, i+1, p, j+1));
            } else {
                while ((p[j]=='.' && s[i]!='\0') || s[i]==p[j]) {
                    if (isMatch(s, i, p, j+2)==true) return true;
                    else i++;
                }
                return isMatch(s, i, p, j+2);
            }
        }
    }
    
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};

3.
思路1: DP

关键在于如何处理这个'*'号。

状态：和Mininum Edit Distance这类题目一样。
dp[i][j]表示s[0:i-1]是否能和p[0:j-1]匹配。

递推公式：由于只有p中会含有regular expression，所以以p[j-1]来进行分类。
p[j-1] != '.' && p[j-1] != '*'：dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1])
p[j-1] == '.'：dp[i][j] = dp[i-1][j-1]

而关键的难点在于 p[j-1] = '*'。由于星号可以匹配0，1，乃至多个p[j-2]。
1. 匹配0个元素，即消去p[j-2]，此时p[0: j-1] = p[0: j-3]
dp[i][j] = dp[i][j-2]

2. 匹配1个元素，此时p[0: j-1] = p[0: j-2]
dp[i][j] = dp[i][j-1]

3. 匹配多个元素，此时p[0: j-1] = { p[0: j-2], p[j-2], ... , p[j-2] }
dp[i][j] = dp[i-1][j] && (p[j-2]=='.' || s[i-2]==p[j-2])

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        // string size from 0 to m
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        // both empty string
        dp[0][0]=true;
        
        // if p is empty, s must be empty. if s is empty, p may not be empty, e.g., a*
        for (int i=0; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (p[j-1]!='.' && p[j-1]!='*') {
                    if (i>0) dp[i][j]=(dp[i-1][j-1] && s[i-1]==p[j-1]);
                } else if (p[j-1]=='.') {
                    if (i>0) dp[i][j]=dp[i-1][j-1];
                } else {
                    // j must be greater than 1
                    if (dp[i][j-1] || dp[i][j-2]) dp[i][j]=true;
                    if (i>0) {
                        if (dp[i-1][j] && (p[j-2]=='.' || p[j-2]==s[i-1])) {
                            dp[i][j]=true;
                        }
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};


http://articles.leetcode.com/regular-expression-matching

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

2.

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


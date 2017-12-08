题目和regular expression matching 有点像， 除了＊不在表示任意count, 而是1-100 的count，

  class Solution {
  public:
      bool isMatch(string& s, int sIdx, string& p, int pIdx) {
          if (pIdx==p.size()) return sIdx==s.size();

          if (p[pIdx+1]!='*') {
              return ((p[pIdx]=='.' && s[sIdx]!='\0') || (p[pIdx]==s[sIdx])) && isMatch(s, sIdx+1, p, pIdx+1);
          } else {
        	  int count=0;
              while (((p[pIdx]=='.' && s[sIdx]!='\0') || (p[pIdx]==s[sIdx])) && count <10 ) {
                  if (isMatch(s, sIdx+1, p, pIdx+2)==true) return true;
                  sIdx++;
                  count++;
              }
              return false;
          }
      }
      bool isMatch(string s, string p) {
          return isMatch(s, 0, p, 0);
      }
  };

  int main() {
	  string a="aaaaaaaaab";
	  string b="a*b";
	  Solution s;
	  bool res=s.isMatch(a, b);
	  return 0;
  }


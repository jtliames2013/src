Question:Implement a regular expression matching. There are three special characters.

* means zero or more of previous characters
. means any single character
+ means one or more of previous characters

http://articles.leetcode.com/regular-expression-matching
* If the next character of p is NOT ‘*’, then it must match the current character of s. Continue pattern matching with the next character of both s and p.
* If the next character of p is ‘*’, then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p… Until we could not match any more characters.

需要用递归Recursion来解，大概思路如下：

- 若p为空，若s也为空，返回true，反之返回false

- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false

- 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配

- 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母

- 返回调用递归函数匹配s和去掉前两个字符的p的结果


class Solution {
public:
    bool isMatch(string& s, int i, string& p, int j) {
        if (j==p.size()) {
            return i==s.size();
        } else {
            if (p[j+1]!='*' && p[j+1]!='+') {
                return (((p[j]=='.' &&  s[i]!='\0') || s[i]==p[j]) && isMatch(s, i+1, p, j+1));
            } else if (p[j+1]=='*') {
                while ((p[j]=='.' && s[i]!='\0') || s[i]==p[j]) {
                    if (isMatch(s, i, p, j+2)==true) return true;
                    else i++;
                }
                return isMatch(s, i, p, j+2);
            } else {
            	while ((p[j]=='.' && s[i]!='\0') || s[i]==p[j]) {
            		if (isMatch(s, i+1, p, j+2)==true) return true;
            		else i++;
            	}
            	return false;
            }
        }
    }

    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
};

int main() {
	string s="abbbc";
	string p="a+c";
	Solution sol;
	bool res=sol.isMatch(s, p);
	cout << res << endl;
	return 0;
}


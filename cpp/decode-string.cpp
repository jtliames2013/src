394. Decode String  QuestionEditorial Solution  My Submissions
Total Accepted: 760 Total Submissions: 2462 Difficulty: Medium
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
Subscribe to see which companies asked this question

Hide Tags Depth-first Search Stack

1. Use stack
class Solution {
public:
    string decodeString(string s) {        
        stack<pair<string,int>> stk;
        stk.push({"", 1});
        int num=0;
        for (int i=0; i<s.size(); i++) {
            if (isdigit(s[i])) {           
                num=num*10+s[i]-'0';                
            } else if (isalpha(s[i])) {
                stk.top().first+=s[i];
            } else if (s[i]=='[') {
                stk.push({"", num});
                num=0;
            } else if (s[i]==']') {
                auto t=stk.top();
                stk.pop();
                for (int i=0; i<t.second; i++) stk.top().first+=t.first;
            }
        }
        
        return stk.top().first;
    }
};

2. Recursive
class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return decodeString(s, i);
    }
private:
    string decodeString(string& s, int& i) {
        string res;
        while (i<s.size()) {            
            if (isalpha(s[i])) {
                res+=s[i];
                ++i;
            } else if (isdigit(s[i])) {
                int num=0;
                while (i<s.size() && isdigit(s[i])) num=num*10+s[i++]-'0';
                ++i; //'['
                string str=decodeString(s, i);
                ++i; //']'
                for (int j=0; j<num; ++j) res+=str;
            } else if (s[i]==']') {
                break;
            }
        }
        
        return res;
    }
};

3. Use stack
class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<string> strs;
        stack<int> nums;
        int num=0;
        strs.push(res);
        
        for (int i=0; i<s.size();) {
            if (isdigit(s[i])) {
                num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num*=10;
                    num+=s[i]-'0';
                    i++;
                }
                nums.push(num);
            } else if (isalpha(s[i])) {
                while (i<s.size() && isalpha(s[i])) {
                    strs.top()+=s[i];
                    i++;
                }
            } else if (s[i]=='[') {
                strs.push("");
                i++;
            } else if (s[i]==']') {
                int n=nums.top();
                nums.pop();
                string s=strs.top();
                strs.pop();
                for (int i=0; i<n; i++) strs.top()+=s;
                i++;
            } else {
                // Should not come here
            }
        }
        return strs.top();
    }
};


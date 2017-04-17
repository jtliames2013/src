71. Simplify Path Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 81087
Total Submissions: 329073
Difficulty: Medium
Contributor: LeetCode
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
Subscribe to see which companies asked this question.

Hide Tags Stack String

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        vector<string> v;
        istringstream iss(path);
        string val;
        while (getline(iss, val, '/')) {
            if (val!=".." && val!="." && !val.empty()) {
                v.push_back(val);
            } else if (val=="..") {
                if (!v.empty()) v.pop_back();
            }
        }
        
        if (v.empty()) res="/";
        else {
            for (auto p:v) {
                res+="/"+p;
            }
        }
        return res;
    }
};


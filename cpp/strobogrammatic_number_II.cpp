247. Strobogrammatic Number II
DescriptionHintsSubmissionsSolutions
Discuss   Editorial Solution Pick One
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

class Solution {
public:
    void dfs(vector<string>& res, string& str, int start, int end) {
        if (start>end) {
            res.push_back(str);
            return;
        }
        for (int i=0; i<l.size(); i++) {
            str[start]=l[i];
            str[end]=r[i];
            if (str.size()>1 && str[0]=='0') continue;
            if (start==end && l[i]!=r[i]) continue;
            dfs(res, str, start+1, end-1);
        }
    }
    
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        string str(n, 0);
        dfs(res, str, 0, n-1);
        return res;
    }
private:
    string l="01689";
    string r="01986";
};


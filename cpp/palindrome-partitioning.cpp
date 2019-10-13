131. Palindrome Partitioning  QuestionEditorial Solution  My Submissions
Total Accepted: 71833 Total Submissions: 249685 Difficulty: Medium
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
Hide Company Tags Bloomberg
Hide Tags Backtracking
Hide Similar Problems (H) Palindrome Partitioning II

class Solution {
public:
    bool isPalin(string& s, int start, int end) {
        while (start<end) {
            if (s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;    
    }
    
    void partition(vector<vector<string>>& res, string& s, vector<string>& output, int start) {
        if (start==s.size()) {
            res.push_back(output);
            return;
        }
        
        for (int i=start; i<s.size(); i++) {
            if (isPalin(s, start, i)) {
                output.push_back(s.substr(start, i-start+1));
                partition(res, s, output, i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> output;
        partition(res, s, output,  0);
        
        return res;
    }
};

2. Cache isPalindrome result
class Solution {
public:
    void buildIsPalin(string& s, vector<vector<bool>>& isPalin) {
        for (int i=s.size()-1; i>=0; i--) {
            for (int j=i; j<s.size(); j++) {
                if (j==i) isPalin[i][j]=true;
                else if (j==i+1) isPalin[i][j]=s[i]==s[j];
                else isPalin[i][j]=(s[i]==s[j] && isPalin[i+1][j-1]);
            }
        }
    }
    
    void partition(vector<vector<string>>& res, string& s, vector<string>& output, vector<vector<bool>>& isPalin, int start) {
        if (start==s.size()) {
            res.push_back(output);
            return;
        }
        
        for (int i=start; i<s.size(); i++) {
            if (isPalin[start][i]) {
                output.push_back(s.substr(start, i-start+1));
                partition(res, s, output, isPalin, i+1);
                output.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int n=s.size();
        if (n==0) return res;
        vector<string> output;
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        buildIsPalin(s, isPalin);
        
        partition(res, s, output, isPalin, 0);
        
        return res;
    }
};

3. Memoization
class Solution {
public:
    void buildIsPalin(string& s, vector<vector<bool>>& isPalin) {
        for (int i=s.size()-1; i>=0; i--) {
            for (int j=i; j<s.size(); j++) {
                if (j==i) isPalin[i][j]=true;
                else if (j==i+1) isPalin[i][j]=s[i]==s[j];
                else isPalin[i][j]=(s[i]==s[j] && isPalin[i+1][j-1]);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n=s.size();
        if (n==0) return vector<vector<string>>();
        vector<vector<vector<string>>> dp(n);
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        buildIsPalin(s, isPalin);
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                if (isPalin[j][i]) {
                    string str=s.substr(j, i-j+1);
                    if (j==0) {
                        vector<string> v;
                        v.push_back(str);
                        dp[i].push_back(v);
                    } else {
                        for (auto v:dp[j-1]) {
                            v.push_back(str);
                            dp[i].push_back(v);
                        }
                    }
                }
            }            
        }
        
        return dp[n-1];
    }
};


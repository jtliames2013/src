https://www.geeksforgeeks.org/shortest-uncommon-subsequence/

class Solution {
public:
    int findSUSLengthDP(string s, string t) {
        int m=s.size(), n=t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i=0; i<=m; ++i) dp[i][0]=1;
        for (int i=0; i<=n; ++i) dp[0][i]=INT_MAX;

        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                int k=j-1;
                for (; k>=0; --k) {
                    if (t[k]==s[i-1]) break;
                }
                if (k==-1) dp[i][j]=1;
                else dp[i][j]=min(dp[i-1][j], dp[i-1][k]==INT_MAX?INT_MAX:dp[i-1][k]+1);
            }
        }

        return dp[m][n]==INT_MAX?-1:dp[m][n];
    }

    int findSUSLength(string s, string t) {
        int m=s.size(), n=t.size();
        auto res=dfs(s, t, 0, 0, m, n);
        return res==INT_MAX?-1:res;
    }

    int dfs(string& s, string& t, int i, int j, int m, int n) {
        if (i==m) return INT_MAX;
        if (j==n) return 1;
        int k=j;
        for (; k<n; ++k) {
            if (t[k]==s[i]) break;
        }
        if (k==n) return 1;
        auto res=dfs(s, t, i+1, j+k+1, m, n);
        return min(dfs(s, t, i+1, j, m, n), res<INT_MAX?res+1:res);
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.findSUSLength("b", "abc") << endl;
    cout << s.findSUSLength("ba", "abc") << endl;
    cout << s.findSUSLength("aba", "abc") << endl;
    cout << s.findSUSLength("babab", "babba") << endl;
    cout << s.findSUSLengthDP("b", "abc") << endl;
    cout << s.findSUSLengthDP("ba", "abc") << endl;
    cout << s.findSUSLengthDP("aba", "abc") << endl;
    cout << s.findSUSLengthDP("babab", "babba") << endl;
    return 0;
}


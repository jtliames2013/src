给一个二维grid，从(0,0)到(0,n)，只允许右，右上，右下，有几种走法。

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0||n==0) return 0;
        vector<int> prev(m);
        prev[0]=1;
        for (int i=1; i<n; i++) {
        	vector<int> curr(m);
        	for (int j=0; j<m; j++) {
        		if (j>0) curr[j]+=prev[j-1];
        		if (j<m-1) curr[j]+=prev[j+1];
        		curr+=prev[j];
        	}
        	prev=curr;
        }

        return prev[0];
    }
};



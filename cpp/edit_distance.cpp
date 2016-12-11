72. Edit Distance 
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

思路：

很多算法教科书上都有的经典二维DP问题。

1. 状态：
DP[i+1][j+1]：word1[0:i] -> word2[0:j]的edit distance。

2. 通项公式：
考虑word1[0:i] -> word2[0:j]的最后一次edit。无非题目中给出的三种方式：

a) 插入一个字符：word1[0:i] -> word2[0:j-1]，然后在word1[0:i]后插入word2[j]
DP[i+1][j+1] = DP[i+1][j]+1

b) 删除一个字符：word1[0:i-1] -> word2[0:j]，然后删除word1[i]
DP[i+1][j+1] = DP[i][j+1]+1

c) 替换一个字符：word1[0:i-1] -> word2[0:j-1]
word1[i] != word2[j]时，word1[i] -> word2[j]：DP[i+1][j+1] = DP[i][j] + 1
word1[i] == word2[j]时：DP[i+1][j+1] = DP[i][j] 

所以min editor distance应该为：
DP[i+1][j+1] = min(DP[i][j] + k, DP[i+1][j]+1, DP[i][j+1]+1) 
word1[i]==word2[j] -> k = 0, 否则k = 1

3. 计算方向：
replace (i, j)      delete (i, j+1)
insert (i+1, j)    (i+1, j+1)

可见要求DP[i+1][j+1]，必须要知道二维矩阵中左上，上方和下方的3个值。所以当我们确定第0行和第0列的值后，就可以从上到下、从左到右的计算了。

4. 起始、边界值
DP[0][i] = i： word1为空，要转化到word2[0:i-1]，需要添加i个字符。
DP[i][0] = i： word2为空，要从word1转化到空字符串，需要删除i个字符。



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

 class Solution {
 public:
     int minDistance(string word1, string word2) {
    	 int m=word1.size();
    	 int n=word2.size();
    	 vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    	 for (int i=0; i<=m; i++) {
    		 dp[i][0]=i;
    	 }
    	 for (int j=0; j<=n; j++) {
    		 dp[0][j]=j;
    	 }

    	 for (int i=1; i<=m; i++) {
    		 for (int j=1; j<=n; j++) {
    			 dp[i][j]=dp[i-1][j-1];
    			 if (word1[i-1]!=word2[j-1]) dp[i][j]++;
    			 dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i][j]);
    		 }
    	 }

    	 return dp[m][n];
     }
 };

2.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();       
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++) dp[i][0]=i;
        for (int j=1; j<=n; j++) dp[0][j]=j;
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int step=(word1[i-1]==word2[j-1])?0:1;
                dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+step);
            }
        }
        
        return dp[m][n];
    }
};

3. 1D dp array
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<int> dp(n+1,0);
        for (int j=1; j<=n; j++) dp[j]=j;
        
        for (int i=1; i<=m; i++) {
            dp[0]=i;
            int prev=i-1;
            for (int j=1; j<=n; j++) {
                int delta=word1[i-1]==word2[j-1]?0:1;
                int temp=dp[j];
                dp[j]=min(min(dp[j-1], dp[j])+1, prev+delta);
                prev=temp;
            }
        }
        
        return dp[n];
    }
};

int main()
{
	return 0;
}


1320. Minimum Distance to Type a Word Using Two Fingers
Hard

118

3

Add to List

Share


You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, for example, the letter A is located at coordinate (0,0), the letter B is located at coordinate (0,1), the letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

Given the string word, return the minimum total distance to type such string using only two fingers. The distance between coordinates (x1,y1) and (x2,y2) is |x1 - x2| + |y1 - y2|. 

Note that the initial positions of your two fingers are considered free so don't count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation: 
Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation: 
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
Example 3:

Input: word = "NEW"
Output: 3
Example 4:

Input: word = "YEAR"
Output: 7
 

Constraints:

2 <= word.length <= 300
Each word[i] is an English uppercase letter.

1. 3D DP
class Solution {
public:
    int minimumDistance(string word) {
        int n=word.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27)));
        return dfs(word, dp, 0, 26, 26);
    }
private:
    int dfs(string& word, vector<vector<vector<int>>>& dp, int start, int left, int right) {
        if (start==word.size()) return 0;
        if (dp[start][left][right]>0) return dp[start][left][right];        
        int next=word[start]-'A';
        dp[start][left][right]=min(dist(left, next)+dfs(word, dp, start+1, next, right),
                                   dist(right, next)+dfs(word, dp, start+1, left, next));
        
        return dp[start][left][right];
    }
    
    int dist(int from, int to) {
        if (from==26) return 0;
        return abs(from/6-to/6)+abs(from%6-to%6);
    }
};

2. 2D DP
class Solution {
public:
    int minimumDistance(string word) {
        int n=word.size();
        vector<vector<int>> dp(n, vector<int>(27));
        return dfs(word, dp, 1, 26);
    }
private:
    int dfs(string& word, vector<vector<int>>& dp, int start, int other) {
        if (start==word.size()) return 0;
        if (dp[start][other]>0) return dp[start][other];
        int curr=word[start]-'A', prev=word[start-1]-'A';
        dp[start][other]=min(dist(other, curr)+dfs(word, dp, start+1, prev),
                             dist(prev, curr)+dfs(word, dp, start+1, other));
        
        return dp[start][other];
    }
    
    int dist(int from, int to) {
        if (from==26) return 0;
        return abs(from/6-to/6)+abs(from%6-to%6);
    }
};

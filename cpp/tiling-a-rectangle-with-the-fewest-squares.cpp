1240. Tiling a Rectangle with the Fewest Squares
Hard

39

106

Favorite

Share
Given a rectangle of size n x m, find the minimum number of integer-sided squares that tile the rectangle.

 

Example 1:



Input: n = 2, m = 3
Output: 3
Explanation: 3 squares are necessary to cover the rectangle.
2 (squares of 1x1)
1 (square of 2x2)
Example 2:



Input: n = 5, m = 8
Output: 5
Example 3:



Input: n = 11, m = 13
Output: 6
 

Constraints:

1 <= n <= 13
1 <= m <= 13

https://en.wikipedia.org/wiki/Squaring_the_square

http://int-e.eu/~bf3/squares/young.cc

class Solution {
public:
    int tilingRectangle(int n, int m) {
        int res = INT_MAX;
        unordered_map<long, int> mp;
        vector<int> h(n+1);
        if (n == m) return 1;
        if (n > m) {
            swap(n, m);
        }
        dfs(res, n, m, mp, h, 0);
        return res;
    }
    
private:    
    void dfs(int& res, int n, int m, unordered_map<long, int>& mp, vector<int> h, int cnt) {
        if (cnt >= res) return;
        bool isFull = true;
        int pos = -1, minH = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (h[i] < m) isFull = false;
            if (h[i] < minH) {
                pos = i;
                minH = h[i];
            }
        }
        if (isFull) {
            res = min(cnt, res);
            return;
        }
        
        long key = 0, base = m + 1;
        for (int i = 1; i <= n; i++) {
            key += h[i] * base;
            base *= m + 1;
        }
        if (mp.find(key)!=mp.end() && mp[key] <= cnt) return;
        mp[key]=cnt;
        
        int end = pos;
        while (end + 1 <= n && h[end + 1] == h[pos] && (end + 1 - pos + 1 + minH) <= m) end++;
        for (int j = end; j >= pos; j--) {
            int curH = j - pos + 1;
            
            vector<int> next=h;
            for (int k = pos; k <= j; k++) {
                next[k] += curH;
            }
            dfs(res, n, m, mp, next, cnt + 1);
        }
    }
};


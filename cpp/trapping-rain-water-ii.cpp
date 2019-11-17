407. Trapping Rain Water II Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8227
Total Submissions: 22820
Difficulty: Hard
Contributor: LeetCode
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.


After the rain, water are trapped between the blocks. The total volume of water trapped is 4.

Subscribe to see which companies asked this question.

Hide Tags Breadth-first Search Heap
Hide Similar Problems

class Solution {
public:
    struct Point {
        int row;
        int col;
        int height;
        Point(int r, int c, int h):row(r), col(c), height(h) {}
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        if (m<=2) return 0;
        int n=heightMap[0].size();
        if (n<=2) return 0;
        int res=0, currmax=INT_MIN;
        
        auto comp=[](Point& a, Point& b){ return a.height>b.height; };
        priority_queue<Point, vector<Point>, decltype(comp)> pq(comp);
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; ++i) {
            pq.push(Point(i, 0, heightMap[i][0]));
            visited[i][0]=true;
            pq.push(Point(i, n-1, heightMap[i][n-1]));
            visited[i][n-1]=true;
        }
        for (int j=1; j<n-1; ++j) {
            pq.push(Point(0, j, heightMap[0][j]));
            visited[0][j]=true;
            pq.push(Point(m-1, j, heightMap[m-1][j]));
            visited[m-1][j]=true;
        }
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            currmax=max(currmax, t.height);
            
            for (int k=0; k<4; ++k) {
                int nr=t.row+delta[k][0];
                int nc=t.col+delta[k][1];
                if (nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==false) {
                    res+=max(0, currmax-heightMap[nr][nc]);
                    pq.push(Point(nr, nc, heightMap[nr][nc]));
                    visited[nr][nc]=true;
                }
            }
        }
        
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};


675. Cut Off Trees for Golf Event
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:
Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:
Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:
Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
Hint: size of the given matrix will not exceed 50x50.

1. BFS, TLE
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(), n=forest[0].size(), res=0;

        // first step: sort the tree position based on its height
        vector<vector<int>> heights;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (forest[i][j]>1) heights.push_back({forest[i][j], i, j});
            }
        }

        sort(heights.begin(), heights.end());
        // second step: accumulate the shortest steps between each two adajacent points in heights[].
        int startRow=0, startCol=0;
        for (int i=0; i<heights.size(); ++i) {
            int steps=bfs(forest, m, n, startRow, startCol, heights[i][1], heights[i][2]);
            if (steps==-1) return -1;
            res+=steps;
            startRow=heights[i][1], startCol=heights[i][2];
        }

        return res;
    }
private:
    int bfs(vector<vector<int>>& forest, int m, int n, int startRow, int startCol, int endRow, int endCol) {
        if (startRow==endRow && startCol==endCol) return 0;
        int steps=0;
        queue<vector<int>> q;
        unordered_set<int> visited;
        q.push({startRow, startCol});
        visited.insert((startRow << 16) | startCol);

        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();

                for (int k=0; k<4; ++k) {
                    int nr=f[0]+delta[k][0];
                    int nc=f[1]+delta[k][1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && forest[nr][nc]>0) {
                        int key=((nr<<16) | nc);
                        if (visited.find(key)==visited.end()) {
                            if (nr==endRow && nc==endCol) return steps+1;
                            q.push({nr, nc});
                            visited.insert(key);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

2. Two end BFS, TLE
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(), n=forest[0].size(), res=0;
        vector<vector<int>> heights;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (forest[i][j]>1) heights.push_back({forest[i][j], i, j});
            }
        }

        sort(heights.begin(), heights.end());
        int startRow=0, startCol=0;
        for (int i=0; i<heights.size(); ++i) {
            int start=((startRow<<16) | startCol), end=((heights[i][1]<<16) | heights[i][2]);
            int steps=bfs(forest, m, n, start, end);
            if (steps==-1) return -1;
            res+=steps;
            startRow=heights[i][1], startCol=heights[i][2];
        }

        return res;
    }
private:
    int bfs(vector<vector<int>>& forest, int m, int  n, int start, int end) {
        if (start==end) return 0;
        int steps=0;
        unordered_set<int> s={start}, e={end}, &small=s, &large=e, next, visited={start, end}; 
        while (!small.empty() && !large.empty()) {
            next.clear();
            for (auto i:small) {
                int row=(i>>16), col=(i & 0xffff);
                for (int k=0; k<4; ++k) {
                    int nr=row+delta[k][0];
                    int nc=col+delta[k][1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && forest[nr][nc]>0) {
                        int key=((nr<<16) | nc);
                        if (large.find(key)!=large.end()) return steps+1;
                        if (visited.find(key)==visited.end()) {
                            next.insert(key);
                            visited.insert(key);
                        }
                    }
                }
            }

            small.clear();
            if (large.size()>next.size()) {
                small=next;
            } else {
                small=large;
                large=next;
            }
            steps++;
        }
        return -1;
    }

    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

3.
Approach #3: Hadlock's Algorithm [Accepted]
Intuition

Without any obstacles, the distance from source = (sr, sc) to target = (tr, tc) is simply taxi(source, target) = 
abs(sr-tr) + abs(sc-tc). This represents a sort of minimum distance that must be travelled. Whenever we walk "away" 
from the target, we increase this minimum by 2, as we stepped 1 move, plus the taxicab distance from our new location 
has increased by one.

Let's call such a move that walks away from the target a detour. It can be proven that the distance from source to target 
is simply taxi(source, target) + 2 * detours, where detours is the smallest number of detours in any path from source to target.

Algorithm

With respect to a source and target, call the detour number of a square to be the lowest number of detours possible 
in any path from source to that square. (Here, detours are defined with respect to target - the number of away steps 
from that target.)

We will perform a priority-first-search in order of detour number. If the target is found, it was found with the lowest 
detour number and therefore the lowest corresponding distance. This motivates using processed, keeping track of when 
nodes are expanded, not visited - nodes could potentially be visited twice.

As each neighboring node can only have the same detour number or a detour number one higher, we will only consider 
at most 2 priority classes at a time. Thus, we can use a deque (double ended queue) to perform this implementation. 
We will place nodes with the same detour number to be expanded first, and nodes with a detour number one higher to 
be expanded after all nodes with the current number are done.

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(), n=forest[0].size(), res=0;
        vector<vector<int>> heights;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (forest[i][j]>1) heights.push_back({forest[i][j], i, j});
            }
        }

        sort(heights.begin(), heights.end());
        int start=0;
        for (int i=0; i<heights.size(); ++i) {
            int end=((heights[i][1]<<16) | heights[i][2]);
            int steps=bfs(forest, m, n, start, end);
            if (steps==-1) return -1;
            res+=steps;
            start=end;
        }

        return res;
    }
private:
    int bfs(vector<vector<int>>& forest, int m, int  n, int start, int end) {
        unordered_set<int> processed={};
        deque<vector<int>> dq;
        dq.push_back({0, start});
        int startRow=(start>>16), startCol=(start & 0xffff);
        int endRow=(end>>16), endCol=(end & 0xffff);

        while (!dq.empty()) {
            auto f=dq.front();
            dq.pop_front();
            int detours=f[0], i=f[1];
            if (processed.find(i)==processed.end()) {
                processed.insert(i);
                int row=(i>>16), col=(i & 0xffff);
                if (i==end) {
                    return abs(startRow-endRow)+abs(startCol-endCol)+2*detours;
                }

                for (int k=0; k<4; ++k) {
                    int nr=row+delta[k][0];
                    int nc=col+delta[k][1];
                    bool closer;
                    if (k<=1) closer=k==0?row>endRow:row<endRow;
                    else closer=k==2?col>endCol:col<endCol;
                    if (nr>=0 && nr<m && nc>=0 && nc<n && forest[nr][nc]>0) {
                        int key=((nr<<16) | nc);
                        if (closer) dq.push_front({detours, key});
                        else dq.push_back({detours+1, key});
                    }
                }
            }
        }
        return -1;
    }

    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};

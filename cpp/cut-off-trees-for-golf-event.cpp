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

class Solution {
public:    
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n , res = 0;
        if(m == 0)return -1;
        n = forest[0].size();
        //first step: sort the tree position based on its height
        vector<vector<int>> heights;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(forest[i][j] > 1)heights.push_back({forest[i][j], i, j});
            }
        }
        sort(heights.begin(), heights.end());
        //second step: accumulate the shortest steps between each two adajacent points in heights[].
        int start_x = 0, start_y = 0; 
        for(int i = 0; i<heights.size(); i++){
            int cnt_steps = BFS(forest, m, n, start_x, start_y, heights[i][1], heights[i][2]); 
            if(cnt_steps == -1)return -1;
            res += cnt_steps;
            start_x = heights[i][1], start_y = heights[i][2];
        }
        return res;
    }
    
    int BFS(vector<vector<int>>& forest, int m, int n, int start_x, int start_y, int des_x, int des_y){
        if(start_x == des_x && start_y == des_y)return 0;
        int steps = 0;
        queue<pair<int, int>> q;
        q.push({start_x, start_y});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[start_x][start_y] = 1;
        while(!q.empty()){
            int qsize = q.size();
            steps++;
            while(qsize-- >0 ){
                int cur_x = q.front().first, cur_y = q.front().second;
                q.pop();
                for(int k = 0; k<4; k++){
                    int x = cur_x + dir[k][0], y = cur_y + dir[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && forest[x][y] > 0 && visited[x][y] == 0){
                        if(x == des_x && y == des_y)return steps;
                        visited[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};


773. Sliding Puzzle
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string begin, end="123450";
        for (int i=0; i<2; i++) {
            for (int j=0; j<3; j++) begin+=board[i][j]+'0';
        }
        
        int res=0;
        if (begin==end) return res;
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({begin, begin.find('0')});
        visited.insert(begin);
        
        while (!q.empty()) {
            res++;
            int size=q.size();
            for (int i=0; i<size; i++) {
                auto t=q.front();
                q.pop();
                for (auto neighbor:delta[t.second]) {                    
                    string str=t.first;
                    swap(str[t.second], str[neighbor]);
                    if (str==end) return res;
                    if (visited.find(str)==visited.end()) {                                                
                        q.push({str, neighbor});
                        visited.insert(str);
                    }
                }
            }
        }
        return -1;
    }
private:
    unordered_map<int, vector<int>> delta{{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}}};
};

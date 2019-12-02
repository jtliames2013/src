913. Cat and Mouse
Hard

237

50

Favorite

Share
A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:

If ever the Cat occupies the same node as the Mouse, the Cat wins.
If ever the Mouse reaches the Hole, the Mouse wins.
If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.

 

Example 1:

Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Explanation:
4---3---1
|   |
2---5
 \ /
  0
 

Note:

3 <= graph.length <= 50
It is guaranteed that graph[1] is non-empty.
It is guaranteed that graph[2] contains a non-zero element. 


Approach 1: Minimax / Percolate from Resolved States
Intuition

The state of the game can be represented as (m, c, t) where m is the location of the mouse, c is the location of the cat, 
and t is 1 if it is the mouse's move, else 2. Let's call these states nodes. These states form a directed graph: the player 
whose turn it is has various moves which can be considered as outgoing edges from this node to other nodes.

Some of these nodes are already resolved: if the mouse is at the hole (m = 0), then the mouse wins; if the cat is where 
the mouse is (c = m), then the cat wins. Let's say that nodes will either be colored \small\text{MOUSE}MOUSE, 
\small\text{CAT}CAT, or \small\text{DRAW}DRAW depending on which player is assured victory.

As in a standard minimax algorithm, the Mouse player will prefer \small\text{MOUSE}MOUSE nodes first, \small\text{DRAW}DRAW 
nodes second, and \small\text{CAT}CAT nodes last, and the Cat player prefers these nodes in the opposite order.

Algorithm

We will color each node marked \small\text{DRAW}DRAW according to the following rule. (We'll suppose the node has node.turn = 
Mouse: the other case is similar.)

("Immediate coloring"): If there is a child that is colored \small\text{MOUSE}MOUSE, then this node will also be colored 
\small\text{MOUSE}MOUSE.

("Eventual coloring"): If all children are colored \small\text{CAT}CAT, then this node will also be colored \small\text{CAT}CAT.

We will repeatedly do this kind of coloring until no node satisfies the above conditions. To perform this coloring efficiently, 
we will use a queue and perform a bottom-up percolation:

Enqueue any node initially colored (because the Mouse is at the Hole, or the Cat is at the Mouse.)

For every node in the queue, for each parent of that node:

Do an immediate coloring of parent if you can.

If you can't, then decrement the side-count of the number of children marked \small\text{DRAW}DRAW. If it becomes zero, 
then do an "eventual coloring" of this parent.

All parents that were colored in this manner get enqueued to the queue.

Proof of Correctness

Our proof is similar to a proof that minimax works.

Say we cannot color any nodes any more, and say from any node colored \small\text{CAT}CAT or \small\text{MOUSE}MOUSE 
we need at most KK moves to win. If say, some node marked \small\text{DRAW}DRAW is actually a win for Mouse, it must 
have been with > K>K moves. Then, a path along optimal play (that tries to prolong the loss as long as possible) must 
arrive at a node colored \small\text{MOUSE}MOUSE (as eventually the Mouse reaches the Hole.) Thus, there must have been 
some transition \small\text{DRAW} \rightarrow \small\text{MOUSE}DRAW→MOUSE along this path.

If this transition occurred at a node with node.turn = Mouse, then it breaks our immediate coloring rule. If it occured 
with node.turn = Cat, and all children of node have color \small\text{MOUSE}MOUSE, then it breaks our eventual coloring rule. 
If some child has color \small\text{CAT}CAT, then it breaks our immediate coloring rule. Thus, in this case node will have 
some child with \small\text{DRAW}DRAW, which breaks our optimal play assumption, as moving to this child ends the game in 
> K>K moves, whereas moving to the colored neighbor ends the game in \leq K≤K moves.


class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[50][50][3]={};
        int degree[50][50][3]={};
        
        // degree[node] : the number of neutral children of this node
        for (int m=0; m<n; ++m) {
            for (int c=0; c<n; ++c) {
                degree[m][c][1]=graph[m].size();
                degree[m][c][2]=graph[c].size();
                for (auto x:graph[c]) {
                    if (x==0) {
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
            
        }

        // enqueued : all nodes that are colored
        list<vector<int>> q;
        for (int i=0; i<n; ++i) {
            for (int t=1; t<=2; ++t) {
                color[0][i][t]=MOUSE;
                q.push_back({0, i, t, MOUSE});
                if (i>0) {
                    color[i][i][t]=CAT;
                    q.push_back({i, i, t, CAT});
                }
            }
        }
        
        // percolate
        while (!q.empty()) {
            // for nodes that are colored :
            auto f=q.front();
            q.pop_front();
            int i=f[0], j=f[1], t=f[2], c=f[3];
            // for every parent of this node i, j, t :
            for (auto parent:parents(graph, i, j, t)) {
                int i2=parent[0], j2=parent[1], t2=parent[2];
                // if this parent is not colored :
                if (color[i2][j2][t2]==DRAW) {
                    // if the parent can make a winning move (ie. mouse to MOUSE), do so
                    if (t2==c){
                        color[i2][j2][t2]=c;
                        q.push_back({i2, j2, t2, c});
                    } else {
                        // else, this parent has degree[parent]--, and enqueue
                        // if all children of this parent are colored as losing moves
                        degree[i2][j2][t2]--;
                        if (degree[i2][j2][t2]==0) {
                            color[i2][j2][t2]=3-t2;
                            q.push_back({i2, j2, t2, 3-t2});
                        }
                    }
                }
            }
        }
        
        return color[1][2][1];
    }
private:
    vector<vector<int>> parents(vector<vector<int>>& graph, int m, int c, int t) {
        vector<vector<int>> res;
        if (t==2) {
            for (int m2:graph[m]) {
                res.push_back({m2, c, 3-t});
            }
        } else {
            for (int c2:graph[c]) {
                if (c2>0) res.push_back({m, c2, 3-t});
            }
        }
        return res;
    }
    
    const int DRAW=0;
    const int MOUSE=1;
    const int CAT=2;
};

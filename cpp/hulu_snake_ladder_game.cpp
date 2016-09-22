http://www.geeksforgeeks.org/snake-ladder-problem-2/

Snake and Ladder Problem
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

If the player reaches a cell which is base of a ladder, the player has to climb up that ladder and if reaches a cell is mouth of the snake, has to go down to the tail of snake without a dice throw.

snakesladders

For example consider the board shown on right side (taken from here), the minimum number of dice throws required to reach cell 30 from cell 1 is 3. Following are steps.

a) First throw two on dice to reach cell number 3 and then ladder to reach 22
b) Then throw 6 to reach 28.
c) Finally through 2 to reach 30.

There can be other solutions as well like (2, 2, 6), (2, 4, 4), (2, 3, 5).. etc.

The idea is to consider the given snake and ladder board as a directed graph with number of vertices equal to the number of cells in the board. The problem reduces to finding the shortest path in a graph. Every vertex of the graph has an edge to next six vertices if next 6 vertices do not have a snake or ladder. If any of the next six vertices has a snake or ladder, then the edge from current vertex goes to the top of the ladder or tail of the snake. Since all edges are of equal weight, we can efficiently find shortest path using Breadth First Search of the graph.

Following is C++ implementation of the above idea. The input is represented by two things, first is ‘N’ which is number of cells in the given board, second is an array ‘move[0…N-1]’ of size N. An entry move[i] is -1 if there is no snake and no ladder from i, otherwise move[i] contains index of destination cell for the snake or the ladder at i.

class Solution {
public:
	int minimumThrows(vector<int> move) {
		int n=move.size();
		if (n==0) return 0;
		vector<bool> visited(n, false);
		queue<int> q;
		q.push(0);
		visited[0]=true;
		int currLevel=1, nextLevel=0, dist=0;

		while (!q.empty()) {
			int f=q.front();
			q.pop();
			currLevel--;

			for (int i=1; i<=6; i++) {
				int next=f+i;
				if (next==n-1) return dist+1;
				if (visited[next]==false) {
					q.push(next);
					visited[next]=true;
					nextLevel++;
					if (move[next]!=-1) {
						next=move[next];
						q.push(next);
						visited[next]=true;
						nextLevel++;
					}
				}
			}

			if (currLevel==0) {
				currLevel=nextLevel;
				nextLevel=0;
				dist++;
			}
		}

	}
};


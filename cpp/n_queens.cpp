51. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Hide Tags Backtracking
Hide Similar Problems (H) N-Queens II


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	bool isValid(int row, int col, vector<int>& pos) {
		for (int i=0; i<pos.size(); i++) {
			if (pos[i]==col || abs(row-i)==abs(pos[i]-col)) {
				return false;
			}
		}

		return true;
	}

	void solve(int n, int row, vector<string>& sol, vector<int>& pos, vector<vector<string> >& res) {
		if (row==n) {
			res.push_back(sol);
			return;
		}

		for (int col=0; col<n; col++) {
			if (isValid(row, col, pos)) {
				pos.push_back(col);
				string s;
				for (int i=0; i<n; i++) {
					if (i==col) s.append("Q");
					else s.append(".");
				}
				sol.push_back(s);
				solve(n, row+1, sol, pos, res);
				pos.pop_back();
				sol.pop_back();
			}
		}
	}

    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string> > res;
    	vector<string> sol;
    	vector<int> pos;
    	solve(n, 0, sol, pos, res);

    	return res;
    }
};

2. print board at the end
class Solution {
public:
    vector<string> getConfig(int n, vector<int>& pos) {
        vector<string> res;
        for (int i=0; i<n; i++) {
            string line;
            for (int j=0; j<n; j++) {
                if (j==pos[i]) line+="Q";
                else line+=".";
            }
            res.push_back(line);
        }
        return res;
    }
    
    bool isValid(int row, int col, vector<int>& pos) {
        for (int i=0; i<pos.size(); i++) {
            if (pos[i]==col || abs(pos[i]-col)==row-i) return false;
        }   
        return true;
    }
    
    void solve(vector<vector<string>>& res, int n, vector<int>& pos, int row) {
        if (row==n) {
            vector<string> config=getConfig(n, pos);
            res.push_back(config);
            return;
        }    
        
        for (int col=0; col<n; col++) {
            if (isValid(row, col, pos)) {
                pos.push_back(col);
                solve(res, n, pos, row+1);
                pos.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> pos;
        solve(res, n, pos, 0);
        
        return res;
    }
};

int main()
{
	return 0;
}


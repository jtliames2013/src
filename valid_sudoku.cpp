#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

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

class Solution {
public:
	void initFlag(vector<bool> &f)
	{
		for (int i = 0; i < 9; i++) f.push_back(false);
	}

    bool isValidSudoku(vector<vector<char> > &board) {
    	vector<bool> flag;

    	for (int row = 0; row < 9; row++)
    	{
    		flag.clear();
    		initFlag(flag);

    		for (int i = 0; i < 9; i++)
    		{
    			if (board[row][i] != '.')
    			{
    				if (flag[board[row][i] - '1'] == true)
    				{
    					return false;
    				}
    				else
    				{
    					flag[board[row][i] - '1'] = true;
    				}
    			}
    		}
    	}

		for (int col = 0; col < 9; col++)
		{
			flag.clear();
			initFlag(flag);

			for (int i = 0; i < 9; i++)
			{
				if (board[i][col] != '.')
				{
					if (flag[board[i][col] - '1'] == true)
					{
						return false;
					}
					else
					{
						flag[board[i][col] - '1'] = true;
					}
				}
			}
		}

		for (int row = 0; row < 3; row++)
		{
			for (int col= 0; col < 3; col++)
			{
				flag.clear();
				initFlag(flag);
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (board[row * 3 + i][col * 3 + j] != '.')
						{
							if (flag[board[row * 3 + i][col * 3 + j] - '1'] == true)
							{
								return false;
							}
							else
							{
								flag[board[row * 3 + i][col * 3 + j] - '1'] = true;
							}
						}
					}
				}
			}
		}

    	return true;
    }
};

int main()
{
	return 0;
}


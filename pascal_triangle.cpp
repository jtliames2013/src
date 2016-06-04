#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		if (numRows <= 0) return res;

		vector<int> prev;
		vector<int> curr;

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0 || j == i)
				{
					curr.push_back(1);
				}
				else
				{
					curr.push_back(prev[j-1] + prev[j]);
				}
			}
			res.push_back(curr);
			prev = curr;
			curr.clear();
		}

		return res;
	}
};

void PrintPascal(vector<vector<int> > v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	Solution s;

	vector<vector<int> > v = s.generate(7);
	PrintPascal(v);

	return 0;
}


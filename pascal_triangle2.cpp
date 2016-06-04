#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res;

    	if (rowIndex < 0) return res;

    	vector<int> prev;
    	for (int i = 0; i < rowIndex + 1; i++)
    	{
    		res.clear();
    		for (int j = 0; j <= i; j++)
    		{
    			if (j == 0 || j == i)
    			{
    				res.push_back(1);
    			}
    			else
    			{
    				res.push_back(prev[j-1]+prev[j]);
    			}
    		}
    		prev = res;
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


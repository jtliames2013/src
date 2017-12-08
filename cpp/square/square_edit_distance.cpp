Leetcode原题： Edit Distance. Follow up: 

1描述用recursion怎么解决（我用的不是recursion）， 
2描述： 如果需要具体输出步骤的话怎么解决，recursion的情况下怎么解决

class Solution {
public:
	int editDistance (string x, string y)
	{
	  if (x.empty())
	     return y.length();
	  else if (y.empty())
	     return x.length();
	  else {
	      int addDistance = editDistance(x, y.substr(1)) + 1;
	      int removeDistance = editDistance(x.substr(1), y) + 1;
	      int delta=(x[0]==y[0])?0:1;
	      int changeDistance = editDistance(x.substr(1), y.substr(1))+delta;
	      return min(min(addDistance, removeDistance), changeDistance);
	  }
	}
};

int main() {
	Solution s;
	int res=s.editDistance("abc", "ac");
	cout << res << endl;
	return 0;
}


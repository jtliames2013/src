#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

class Solution {
public:
	  Solution() {
		  data.resize(1001, 0);
		  cnt=0;
	  }

	  void insert(int val) {
		  if (val<0 || val>1000) return;
		  data[val]++;
		  cnt++;
	  }

	  double getMean() {
		  int sum=0;
		  int count=0;
		  for (int i=0; i<=1000; i++) {
			  if (data[i]!=0) {
				  count+=data[i];
				  sum+=data[i]*i;
			  }
		  }

		  return (double)sum/count;
	  }

	  double getMedian() {
		  int count=0;
		  int m, m1=-1, m2;
		  bool odd=(cnt%2==1);
		  for (int i=0; i<=1000; i++) {
			  if (data[i]!=0) {
				  count+=data[i];
				  if (odd) {
					  if (count>=cnt/2+1) return i;
				  } else {
					  if (count>=cnt/2 && m1==-1) m1=i;
					  if (count>=cnt/2+1) {
						  m2=i;
						  return ((double)(m1+m2))/2;
					  }
				  }
			  }
		  }
	  }

private:
	  vector<int> data;
	  int cnt;
};

int main()
{
	Solution s;
	for (int i=1; i<4; i++) {
		s.insert(i);
	}

	double mean=s.getMean();
	cout << mean << endl;
	double median=s.getMedian();
	cout << median << endl;

	return 0;
}


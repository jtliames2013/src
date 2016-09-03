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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

  // Definition for a point.
  struct Point {
       int x;
       int y;
       Point() : x(0), y(0) {}
       Point(int a, int b) : x(a), y(b) {}
  };

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
		  int target=0;

		  int m, m1, m2;
		  bool odd=(cnt%2==1);
		  for (int i=0; i<=1000; i++) {
			  if (data[i]!=0) {
				  int before=target;
				  int after=target+data[i];
				  if (odd) {
					  if (before<cnt/2+1 && after>=cnt/2+1) {
						  m=i;
					  }
				  } else {
					  if (before<cnt/2 && after>=cnt/2) {
						  m1=i;
					  }
					  if (before<cnt/2+1 && after>=cnt/2+1) {
						  m2=i;
					  }
				  }

				  target+=data[i];
			  }
		  }

		  if (odd) return (double)m;
		  else return (double)(m1+m2)/2;
	  }

private:
	  vector<int> data;
	  int cnt;
  };

int main()
{
	Solution s;
	for (int i=0; i<10; i++) {
		s.insert(i);
	}

	double median=s.getMedian();

	return 0;
}


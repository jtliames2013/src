281. Zigzag Iterator 
 Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]

It should return [1,4,8,2,5,9,3,6,7]. 

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

  class ZigzagIterator {
  public:
	  vector<int> idx;
	  vector<vector<int> > v;
	  int select;

      ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    	  v.push_back(v1);
    	  v.push_back(v2);
    	  idx = {0, 0};
    	  select=v1.size()>0 ? 0 : 1;
      }

      int next() {
    	  if (hasNext()) {
    		  int res=v[select][idx[select]];
    		  idx[select]++;
    		  for (int i=0; i<2; i++) {
    			  select=(select+1)%2;
    			  if (idx[select]<v[select].size()) break;
    		  }

    		  return res;
    	  } else {
    		  return 0;
    	  }
      }

      bool hasNext() {
    	  return (idx[0]<v[0].size() || idx[1]<v[1].size());
      }
  };

2. k lists

class ZigzagIterator {
public:
    void tryAdvance() {
        int curr=row;
        while (1) {
            if (idx[row]<list[row].size()) break;
            row=(row+1)%size;
            if (row==curr) break;
        }
    }
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        list.push_back(v1);
        list.push_back(v2);
        idx.resize(2, 0);
        row=0;
        size=2;
        tryAdvance();
    }

    int next() {
        if (hasNext()) {
            int res=list[row][idx[row]];
            idx[row]++;
            row=(row+1)%size;
            tryAdvance();
            return res;
        } else {
            return 0;
        }
    }

    bool hasNext() {
        if (idx[row]<list[row].size()) return true;
        else return false;
    }
private:
    vector<vector<int>> list;
    vector<int> idx;
    int row;
    int size;
};

3. Implement remove() that remove the previous next
class ZigzagIterator {
public:
    void tryAdvance() {
        int currRow=row;
        while (1) {
            if (idx[row]<lists[row].size()) break;
            row=(row+1)%size;
            if (row==currRow) break;
        }
    }
    
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        lists.push_back(v1);
        lists.push_back(v2);
        idx.resize(2, 0);
        row=0;
        size=2;
        tryAdvance();
    }

    int next() {
        if (hasNext()) {
            int res=lists[row][idx[row]];
            toRemove.push_back({row, idx[row]});
            idx[row]++;
            row=(row+1)%size;
            tryAdvance();
            return res;
        } else {
            return -1;
        }
    }

    bool hasNext() {
        if (idx[row]<lists[row].size()) return true;
        else return false;
    }
    
    void remove() {
        if (toRemove.size()==0) return;
        int i=toRemove.back().first;
        int j=toRemove.back().second;
        toRemove.pop_back();
        lists[i].erase(lists[i].begin()+j);
    }
private:
    vector<vector<int>> lists;
    vector<int> idx;
    vector<pair<int,int>> toRemove;
    int row;
    int size;
};


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
	vector<int> v1={1,2};
	vector<int> v2={3,4,5,6};
	ZigzagIterator i(v1, v2);
	while (i.hasNext()) {
		cout << i.next();
	}
	return 0;
}


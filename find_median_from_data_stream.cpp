295. Find Median from Data Stream 
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.

Hide Company Tags Google
Hide Tags Heap Design

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class MedianFinder {
 public:
	 priority_queue<int> small;
	 priority_queue<int, vector<int>, greater<int>> large;

     // Adds a number into the data structure.
     void addNum(int num) {
    	 if (!large.empty() && num > large.top()) {
    		 large.push(num);
    	 } else {
    		 small.push(num);
    	 }

    	 if (small.size() > large.size()+1) {
    		 large.push(small.top());
    		 small.pop();
    	 } else if (large.size() > small.size()+1) {
    		 small.push(large.top());
    		 large.pop();
    	 }
     }

     // Returns the median of current data stream
     double findMedian() {
    	 if (small.size()==large.size()) return (small.top()+large.top())/2.0;
    	 else if (small.size()>large.size()) return small.top();
    	 else return large.top();
     }

    double findMean() {
        int sum=0;
        int count=0;
        for (int i=0; i<1001; i++) {
            if (data[i]!=0) {
                count+=data[i];
                sum+=count*i;
            }
        }

        return ((double)sum)/count;
    }
 };

2.
class MedianFinder {
public:
    MedianFinder() {
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if (small.empty() || num<=small.top()) small.push(num);
        else large.push(num);
        
        if (small.size()>large.size()+1) {
            large.push(small.top());
            small.pop();
        } else if (large.size()>small.size()+1) {
            small.push(large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (small.empty()&&large.empty()) return 0;
        if (small.size()==large.size()) return (small.top()+large.top())/2.0;
        else if (small.size()>large.size()) return small.top();
        else return large.top();
    }
    
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

 // Your MedianFinder object will be instantiated and called as such:
 // MedianFinder mf;
 // mf.addNum(1);
 // mf.findMedian();

int main()
{
	return 0;
}


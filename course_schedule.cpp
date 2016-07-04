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
	struct Node {
		unordered_set<int> neighbors;
	};

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	// [0, 1] 0 ---> 1
    	vector<Node> graphIncoming(numCourses);
    	vector<Node> graphOutgoing(numCourses);

    	for (auto p:prerequisites) {
    		graphOutgoing[p.first].neighbors.insert(p.second);
    		graphIncoming[p.second].neighbors.insert(p.first);
    	}

    	vector<int> sorted;
    	unordered_set<int> s;
    	for (int i=0; i<graphIncoming.size(); i++) {
    		if (graphIncoming[i].neighbors.size()==0) {
    			s.insert(i);
    		}
    	}

    	while (!s.empty()) {
    		int n=*s.begin();
    		sorted.push_back(n);
    		s.erase(s.begin());

    		for (auto it=graphOutgoing[n].neighbors.begin(); it!=graphOutgoing[n].neighbors.end(); it++) {
    			graphIncoming[*it].neighbors.erase(n);
    			if (graphIncoming[*it].neighbors.size()==0) {
    				s.insert(*it);
    			}
    		}
    		graphOutgoing[n].neighbors.clear();
    	}

    	for (int i=0; i<graphIncoming.size(); i++) {
    		if (graphIncoming[i].neighbors.size()>0) return false;
    	}

    	return true;
    }
};

2. 

class Solution {

public:

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        // [0, 1] 1 is prerequisite of 0 so 1-->0

        if (numCourses==0) return true;

        vector<unordered_set<int>> outgoingGraph(numCourses);

        vector<int> incomingCount(numCourses, 0);

        

        for (auto p:prerequisites) {

	    // NOTE: pair could be duplicate so check here to avoid incorectly increment count
            if (outgoingGraph[p.second].find(p.first)==outgoingGraph[p.second].end()) {
                
                outgoingGraph[p.second].insert(p.first);

                incomingCount[p.first]++;
            }

        }

        

        unordered_set<int> st;

        for (int i=0; i<incomingCount.size(); i++) {

            if (incomingCount[i]==0) st.insert(i);

        }

        

        while (!st.empty()) {

            int n=*st.begin();

            st.erase(st.begin());

            for (auto neighbor:outgoingGraph[n]) {

                incomingCount[neighbor]--;

                if (incomingCount[neighbor]==0) st.insert(neighbor);

            }

            outgoingGraph[n].clear();

        }

        

        for (int i=0; i<incomingCount.size(); i++) {

            if (incomingCount[i]>0) return false;

        }

        return true;

  }

};

int main()
{
	return 0;
}



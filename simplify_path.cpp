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
    string simplifyPath(string path) {
    	stack<string> paths;
    	string res;
    	int start=-1;
    	int end=-1;
    	for (int i=0; i<path.size(); i++) {
    		if (path[i]=='/') {
    			if (start==-1) {
    				start=i;
    			} else {
    				end=i;
    				if (end-start>1) {
						string dir=path.substr(start+1, end-start-1);
						if (dir.compare("..")==0) {
							if (!paths.empty()) paths.pop();
						} else if (dir.compare(".")!=0) {
							paths.push(dir);
						}
    				}
    				start=end;
    			}
    		}
    	}

		if (start<path.size()-1) {
			string dir=path.substr(start+1);
			if (dir.compare("..")==0) {
				if (!paths.empty()) paths.pop();
			} else if (dir.compare(".")!=0) {
				paths.push(dir);
			}
		}

    	if (paths.empty()) {
    		res.insert(0, "/");
    	} else {
			while (!paths.empty()) {
				res.insert(0, paths.top());
				paths.pop();
				res.insert(0, "/");
			}
    	}
    	return res;
    }
};

2. use istringstream and vector

class Solution {

public:

    string simplifyPath(string path) {

        istringstream iss(path);

        vector<string> v;

        string res;

        string val;

        while (getline(iss, val, '/')) {

            if (val!="." && val!=".." &&!val.empty()) {

                v.push_back(val);

            } else if (val=="..") {

                if (v.size()>0) {

                    v.erase(v.end()-1, v.end());

                }

            }

        }

        

        if (v.size()==0) return "/";

        for (int i=0; i<v.size(); i++) {

            res+="/"+v[i];

        }

        

        return res;

    }

};

int main()
{
	return 0;
}



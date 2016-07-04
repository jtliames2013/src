146. LRU Cache 
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Hide Company Tags Google Uber Facebook Twitter Zenefits Amazon Microsoft Snapchat Yahoo Bloomberg Palantir
Hide Tags Design

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

class LRUCache{
public:
    class CacheEntry {
    public:    
        int key;
        int val;
        CacheEntry(int k, int v): key(k), val(v) {}
    };
    
     LRUCache(int capacity) {
    	 size=capacity;
     }

     int get(int key) {
         auto iter=table.find(key);
         if (iter!=table.end()) {
             if (iter->second!=data.begin()) {
                 data.erase(iter->second);
                 data.push_front(*(iter->second));
                 table[key]=data.begin();
             }
             return data.begin()->val;
         } else {
             return -1;
         }
     }

     void set(int key, int value) {
         auto iter=table.find(key);
         if (iter!=table.end()) {
             if (iter->second!=data.begin()) {
                 data.erase(iter->second);
                 data.push_front(*(iter->second));
                 table[key]=data.begin();
             } 
             data.begin()->val=value;
         } else {
             if (table.size()==size) {
                int k=data.back().key;
                table.erase(k);
                data.pop_back();
             }
             CacheEntry elem(key, value);
             data.push_front(elem);
             table[key]=data.begin();
         }
     }
     
private:
    int size;
    list<CacheEntry> data;
    map<int, list<CacheEntry>::iterator> table;
};

int main()
{
	return 0;
}


355. Design Twitter 
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
Hide Company Tags Amazon Twitter
Hide Tags Hash Table Heap Design

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

  class Twitter {
  public:
	  class Compare {
	  public:
		  bool operator() (pair<vector<pair<int, int> >::iterator, int> iter1, pair<vector<pair<int, int> >::iterator, int> iter2) {
			  return iter1.first->first < iter2.first->first;
		  }
	  };
      /** Initialize your data structure here. */
      Twitter() {
    	  time=0;
      }

      /** Compose a new tweet. */
      void postTweet(int userId, int tweetId) {
    	  follow(userId, userId);
    	  if (tweet[userId].size()>=10) tweet[userId].pop_back();
    	  tweet[userId].insert(tweet[userId].begin(), {time++, tweetId});
      }

      /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
      vector<int> getNewsFeed(int userId) {
    	  vector<int> res;
    	  priority_queue<pair<vector<pair<int, int> >::iterator, int>, vector<pair<vector<pair<int, int> >::iterator, int>>, Compare > pq;
    	  for (auto f:followee[userId]) {
    		  if (!tweet[f].empty()) pq.push({tweet[f].begin(), f});
    	  }

    	  while (1) {
    		  if (res.size()==10 || pq.empty()) break;
    		  auto t=pq.top();
    		  pq.pop();
    		  res.push_back(t.first->second);
    		  int id=t.second;
    		  t.first++;
    		  if (t.first!=tweet[id].end()) pq.push({t.first, id});
    	  }
    	  return res;
      }

      /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
      void follow(int followerId, int followeeId) {
    	  followee[followerId].insert(followeeId);
      }

      /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
      void unfollow(int followerId, int followeeId) {
    	  if (followerId!=followeeId) followee[followerId].erase(followeeId);
      }
  private:
      int time;
      unordered_map<int, set<int> > followee;
      unordered_map<int, vector<pair<int, int> > > tweet;
  };

  /**
   * Your Twitter object will be instantiated and called as such:
   * Twitter obj = new Twitter();
   * obj.postTweet(userId,tweetId);
   * vector<int> param_2 = obj.getNewsFeed(userId);
   * obj.follow(followerId,followeeId);
   * obj.unfollow(followerId,followeeId);
   */

int main()
{
	return 0;
}


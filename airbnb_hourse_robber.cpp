Airbnb: Maximum Room Days
给一个数组代表reservation request，suppose start date, end date back to back.
比如[5,1,1,5]代表如下预定：
Jul 1-Jul6
Jul6-Jul7
Jul7-Jul8
jul8-Jul13
当然最开始那个Jul 1是随便选就好的啦。
现在input的意义搞清楚了。还有一个限制，就是退房跟开始不能是同一天，比如如果接了Jul 1-Jul6，Jul6-Jul7就不能接了。那问题就是给你个数组，算算最多能把房子租出去多少天。这个例子的话就是10天。
[4,9,6]=10. 

[4,10,3,1,5]=15

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
    int rob(vector<int>& nums) {
    	int size=nums.size();
    	if (size==0) return 0;
    	vector<int> res(size);

    	for (int i=0; i<size; i++) {
    		if (i==0) {
    			res[i]=nums[i];
    		} else if (i==1) {
    			res[i]=max(nums[i], nums[i-1]);
    		} else {
    			res[i]=max(res[i-1], res[i-2]+nums[i]);
    		}
    	}

    	return res[size-1];
    }
};

==========================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if (size==0) return 0;
        vector<int> dp(size+1, 0);
        dp[1]=nums[0];
        for (int i=2; i<=size; i++) {
            dp[i]=max(dp[i-1], nums[i-1]+dp[i-2]);
        }
        
        return dp[size];
    }
};

==================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if (size==0) return 0;
        int odd=0, even=0;
        
        for (int i=0; i<nums.size(); i++) {
            if (i%2==1) odd=max(even, odd+nums[i]);
            else even=max(odd, even+nums[i]);
        }
        
        return max(odd, even);
    }
};

3. get the list of houses
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<vector<int>> select(n+1);
        vector<int> dp(n+1, 0);
        dp[1]=nums[0];
        select[1].push_back({0});
        for (int i=2; i<=n; i++) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
            if (dp[i-1]<dp[i-2]+nums[i-1]) {
                select[i]=select[i-2];
                select[i].push_back(i-1);
            } else {
                select[i]=select[i-1];
            }
        }
        
        for (auto s:select[n]) cout << s << " ";
        cout << endl;
        return dp[n];
    }
};

int main()
{
	return 0;
}

4. get list of house, use vector to remember previous house.
  class Solution {
  public:
      int rob(vector<int>& nums) {
          int n=nums.size();
          if (n==0) return 0;
          vector<int> dp(n+1, 0);
          vector<int> pos(n+1, 0);
          dp[1]=nums[0];
          pos[1]=1;
          for (int i=2; i<=n; i++) {
              dp[i]=max(dp[i-1], dp[i-2]+nums[i-1]);
              if (dp[i-1]>dp[i-2]+nums[i-1]) {
            	  pos[i]=i-1;
              } else {
            	  pos[i]=i-2;
              }
          }

          vector<int> res;
          for (int i=n; i>0; ) {
        	  if (i==1) {
        		  res.insert(res.begin(), i);
        		  i--;
        	  } else if (pos[i]==i-2) {
        		  res.insert(res.begin(), i);
        		  i-=2;
        	  } else if (pos[i]==i-1) {
        		  i--;
        	  }
          }

          return dp[n];
      }
  };

  int main()
  {
	vector<int> nums={1,2,3};
	Solution s;
	s.rob(nums);
  	return 0;
  }



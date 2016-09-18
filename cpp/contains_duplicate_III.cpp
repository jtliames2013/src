220. Contains Duplicate III 
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

Hide Company Tags Palantir Airbnb
Hide Tags Binary Search Tree
Hide Similar Problems (E) Contains Duplicate (E) Contains Duplicate II

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
	long long abs(long long a, long long b) {
		return a>b? a-b : b-a;
	}

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	map<int, int> m;
    	for (int i=0; i<nums.size(); i++) {
    		if (t==0) {
    			auto res=m.find(nums[i]);
    			if (res!=m.end()) {
    				if (i-(*res).second<=k) return true;
    			}
    			m[nums[i]]=i;
    		} else {
    			auto res=m.find(nums[i]/t);
    			if (res!=m.end()) {
					if (abs(nums[i], nums[(*res).second])<=t && i-(*res).second<=k) return true;
				}

    			res=m.find(nums[i]/t-1);
    			if (res!=m.end()) {
    				if (abs(nums[i], nums[(*res).second])<=t && i-(*res).second<=k) return true;
    			}

    			res=m.find(nums[i]/t+1);
    			if (res!=m.end()) {
    				if (abs(nums[i], nums[(*res).second])<=t && i-(*res).second<=k) return true;
    			}

    			m[nums[i]/t]=i;
    		}
    	}

    	return false;
    }
};

2.
这道题跟之前两道Contains Duplicate 包含重复值和Contains Duplicate II 包含重复值之二的关联并不是很大，前两道起码跟重复值有关，这道题的焦点不是在重复值上面，反而是关注与不同的值之间的关系，这里有两个限制条件，两个数字的坐标差不能大于k，值差不能大于t。这道题如果用brute force会超时，所以我们只能另辟蹊径。这里我们使用map数据结构来解,用来记录数字和其下标之间的映射。 这里需要两个指针i和j，刚开始i和j都指向0，然后i开始向右走遍历数组，如果i和j之差大于k，且m中有nums[j]，则删除并j加一。这样保证了m中所有的数的下标之差都不大于k，然后我们用map数据结构的lower_bound()函数来找一个特定范围，就是大于或等于nums[i] - t的地方，所有小于这个阈值的数和nums[i]的差的绝对值会大于t (可自行带数检验)。然后检测后面的所有的数字，如果数的差的绝对值小于等于t，则返回true。最后遍历完整个数组返回false。代码如下：

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> st;
        
        for (int i=0; i<nums.size(); i++) {
            auto l=st.lower_bound(nums[i]-t);
            if (l!=st.end() && abs(*l-nums[i])<=t) return true;
            st.insert(nums[i]);
            if (st.size()>k) st.erase(nums[i-k]);
        }
        
        return false;
    }
};

int main()
{
	return 0;
}

220. Contains Duplicate III
Question Editorial Solution 
March 25, 2016
Question

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
Quick Navigation
Summary
Solutions
Approach #1 (Naive Linear Search) [Time Limit Exceeded]
Approach #2 (Binary Search Tree) [Accepted]
Approach #3 (Buckets) [Accepted]
See Also
Summary

This article is for intermediate readers. It introduces the following ideas: Binary Search Tree, HashMap, and Buckets.

Solutions

Approach #1 (Naive Linear Search) [Time Limit Exceeded]

Intuition

Compare each element with the previous kk elements and see if their difference is at most tt.

Algorithm

This problem requires us to find ii and jj such that the following conditions are satisfied:

\bigl| i-j \bigr| \le k
​∣
​∣
​​ i−j
​∣
​∣
​​ ≤k
\bigl| \mathrm{nums}[i] - \mathrm{nums}[j] \bigr| \le t
​∣
​∣
​​ nums[i]−nums[j]
​∣
​∣
​​ ≤t
The naive approach is the same as Approach #1 in Contains Duplicate II solution, which keeps a virtual sliding window that holds the newest kk elements. In this way, Condition 1 above is always satisfied. We then check if Condition 2 is also satisfied by applying linear search.

Java

public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = Math.max(i - k, 0); j < i; ++j) {
            if (Math.abs(nums[i] - nums[j]) <= t) return true;
        }
    }
    return false;
}
// Time limit exceeded.
Complexity Analysis

Time complexity : O(n \min(k,n))O(nmin(k,n)). It costs O(\min(k, n))O(min(k,n)) time for each linear search. Note that we do at most nn comparisons in one search even if kk can be larger than nn.

Space complexity : O(1)O(1). We only used constant auxiliary space.

Approach #2 (Binary Search Tree) [Accepted]

Intuition

If elements in the window are maintained in sorted order, we can apply binary search twice to check if Condition 2 is satisfied.

By utilizing self-balancing Binary Search Tree, one can keep the window ordered at all times with logarithmic time insert and delete.

Algorithm

The real bottleneck of Approach #1 is due to all elements in the sliding window are being scanned to check if Condition 2 is satisfied. Could we do better?

If elements in the window are in sorted order, we can apply Binary Search twice to search for the two boundaries x+tx+t and x-tx−t for each element xx.

Unfortunately, the window is unsorted. A common mistake here is attempting to maintain a sorted array. Although searching in a sorted array costs only logarithmic time, keeping the order of the elements after insert and delete operation is not as efficient. Imagine you have a sorted array with kk elements and you are adding a new item xx. Even if you can find the correct position in O(\log k)O(logk) time, you still need O(k)O(k) time to insert xx into the sorted array. The reason is that you need to shift all elements after the insert position one step backward. The same reasoning applies to removal as well. After removing an item from position ii, you need to shift all elements after ii one step forward. Thus, we gain nothing in speed compared to the naive linear search approach above.

To gain an actual speedup, we need a dynamic data structure that supports faster insert, search and delete. Self-balancing Binary Search Tree (BST) is the right data structure. The term Self-balancing means the tree automatically keeps its height small after arbitrary insert and delete operations. Why does self-balancing matter? That is because most operations on a BST take time directly proportional to the height of the tree. Take a look at the following non-balanced BST which is skewed to the left:

            6
           /
          5
         /
        4
       /
      3
     /
    2
   /
  1
Figure 1. A non-balanced BST that is skewed to the left.

Searching in the above BST degrades to linear time, which is like searching in a linked list. Now compare to the BST below which is balanced:

          4
        /   \
       2     6
      / \   /
     1   3  5
Figure 2. A balanced BST.

Assume that nn is the total number of nodes in the tree, a balanced binary tree maintains its height in the order of h = \log nh=logn. Thus it supports O(h) = O(\log n)O(h)=O(logn) time for each of insert, search and delete operations.

Here is the entire algorithm in pseudocode:

Initialize an empty BST set
Loop through the array, for each element xx
Find the smallest element ss in set that is greater than or equal to xx, return true if s - x \leq ts−x≤t
Find the greatest element gg in set that is smaller than or equal to xx, return true if x - g \leq tx−g≤t
Put xx in set
If the size of the set is larger than kk, remove the oldest item.
Return false
One may consider the smallest element ss that is greater or equal to xx as the successor of xx in the BST, as in: "What is the next greater value of xx?". Similarly, we consider the greatest element gg that is smaller or equal to xx as the predecessor of xx in the BST, as in: "What is the previous smaller value of xx?". These two values ss and gg are the two closest neighbors from xx. Thus by checking the distance from them to xx, we can conclude if Condition 2 is satisfied.

Java

public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
    TreeSet<Integer> set = new TreeSet<>();
    for (int i = 0; i < nums.length; ++i) {
        // Find the successor of current element
        Integer s = set.ceiling(nums[i]);
        if (s != null && s <= nums[i] + t) return true;

        // Find the predecessor of current element
        Integer g = set.floor(nums[i]);
        if (g != null && nums[i] <= g + t) return true;

        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
Complexity Analysis

Time complexity : O(n \log (\min(n,k)))O(nlog(min(n,k))). We iterate through the array of size nn. For each iteration, it costs O(\log \min(k, n))O(logmin(k,n)) time (search, insert or delete) in the BST, since the size of the BST is upper bounded by both kk and nn.

Space complexity : O(\min(n,k))O(min(n,k)). Space is dominated by the size of the BST, which is upper bounded by both kk and nn.

Note

When the array's elements and tt's value are large, they can cause overflow in arithmetic operation. Consider using a larger size data type instead, such as long.

C++'s std::set, std::set::upper_bound and std::set::lower_bound are equivalent to Java's TreeSet, TreeSet::ceiling and TreeSet::floor, respectively. Python does not provide a Self-balancing BST through its library.

Approach #3 (Buckets) [Accepted]

Intuition

Inspired by bucket sort, we can achieve linear time complexity in our problem using buckets as window.

Algorithm

Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket is then sorted individually, using a different sorting algorithm. Here is an illustration of buckets.

Illustration of buckets

Figure 3. Illustration of buckets.

From the above example, we have 8 unsorted integers. We create 5 buckets covering the inclusive ranges of [0,9], [10,19], [20, 29], [30, 39], [40, 49][0,9],[10,19],[20,29],[30,39],[40,49] individually. Each of the eight elements is in a particular bucket. For element with value xx, its bucket label is x / wx/w and here we have w = 10w=10. Sort each bucket using some other sorting algorithm and then collect all of them bucket by bucket.

Back to our problem, the critical issue we are trying to solve is:

For a given element xx is there an item in the window that is within the range of [x-t, x+t][x−t,x+t]?
Could we do this in constant time?
Let us consider an example where each element is a person's birthday. Your birthday, say some day in March, is the new element xx. Suppose that each month has 3030 days and you want to know if anyone has a birthday within t = 30t=30 days of yours. Immediately, we can rule out all other months except February, March, April.

The reason we know this is because each birthday belongs to a bucket we called month! And the range covered by the buckets are the same as distance tt which simplifies things a lot. Any two elements that are not in the same or adjacent buckets must have a distance greater than tt.

We apply the above bucketing principle and design buckets covering the ranges of ..., [0,t], [t+1, 2t+1], ......,[0,t],[t+1,2t+1],.... We keep the window using this buckets. Then, each time, all we need to check is the bucket that xx belongs to and its two adjacent buckets. Thus, we have a constant time algorithm for searching almost duplicate in the window.

One thing worth mentioning is the difference from bucket sort – Each of our buckets contains at most one element at any time, because two elements in a bucket means "almost duplicate" and we can return early from the function. Therefore, a HashMap with an element associated with a bucket label is enough for our purpose.

Java

public class Solution {
    // Get the ID of the bucket from element value x and bucket width w
    // In Java, `-3 / 5 = 0` and but we need `-3 / 5 = -1`.
    private long getID(long x, long w) {
        return x < 0 ? (x + 1) / w - 1 : x / w;
    }

    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (t < 0) return false;
        Map<Long, Long> d = new HashMap<>();
        long w = (long)t + 1;
        for (int i = 0; i < nums.length; ++i) {
            long m = getID(nums[i], w);
            // check if bucket m is empty, each bucket may contain at most one element
            if (d.containsKey(m))
                return true;
            // check the neighbor buckets for almost duplicate
            if (d.containsKey(m - 1) && Math.abs(nums[i] - d.get(m - 1)) < w)
                return true;
            if (d.containsKey(m + 1) && Math.abs(nums[i] - d.get(m + 1)) < w)
                return true;
            // now bucket m is empty and no almost duplicate in neighbor buckets
            d.put(m, (long)nums[i]);
            if (i >= k) d.remove(getID(nums[i - k], w));
        }
        return false;
    }
}
Complexity Analysis

Time complexity : O(n)O(n). For each of the nn elements, we do at most three searches, one insert, and one delete on the HashMap, which costs constant time on average. Thus, the entire algorithm costs O(n)O(n) time.

Space complexity : O(\min(n,k))O(min(n,k)). Space is dominated by the HashMap, which is linear to the size of its elements. The size of the HashMap is upper bounded by both nn and kk. Thus the space complexity is O(\min(n, k))O(min(n,k)).

See Also

Problem 217 Contains Duplicate
Problem 219 Contains Duplicate II
 
 
 
 
 
 
 
 
Average Rating: 4.20 (10 votes)

Subscribe
subscribe for articles.

❮ Previous Next ❯


Join the conversation
Login to Reply
 jimmyzzxhlh
jimmyzzxhlh commented last month
For BST solution, the code can still get overflow error if the input case is like
[2147483646, 2147483647]
and k = 1, t = 2147483647
The solution will return false, but it should be true.


View original thread
Frequently Asked Questions | Terms of Service



Copyright © 2016 LeetCode

Send Feedback

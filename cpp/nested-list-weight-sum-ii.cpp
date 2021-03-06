364. Nested List Weight Sum II
Medium

413

101

Favorite

Share
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 8 
Explanation: Four 1's at depth 1, one 2 at depth 2.
Example 2:

Input: [1,[4,[6]]]
Output: 17 
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.

LinkedIn
|
20

DiDi
|
4

Facebook
|
2

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int getDepth(vector<NestedInteger>& nestedList) {
        int depth=1;
        for (auto& n:nestedList) {
            if (!n.isInteger()) depth=max(depth, getDepth(n.getList())+1);
        }
        
        return depth;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList, int depth) {
        int sum=0;
        for (auto& n:nestedList) {
            if (n.isInteger()) sum+=n.getInteger()*depth;
            else sum+=depthSumInverse(n.getList(), depth-1);
        }
        
        return sum;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth=getDepth(nestedList);
        return depthSumInverse(nestedList, depth);
    }
};

2. add level by level
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList, int prevSum) {
        int sum=prevSum;
        vector<NestedInteger> l;
        for (auto& n:nestedList) {
            if (n.isInteger()) sum+=n.getInteger();
            else l.insert(l.end(), n.getList().begin(), n.getList().end());
        }
        
        return l.empty()?sum:sum+depthSumInverse(l, sum);
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        return depthSumInverse(nestedList, 0);
    }
};


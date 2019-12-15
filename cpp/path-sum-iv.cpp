666. Path Sum IV
Medium

157

184

Favorite

Share
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:

The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
 

Given a list of ascending three-digits integers representing a binary tree with the depth smaller than 5, you need to return the sum of all paths from the root towards the leaves.

Example 1:

Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
 

Example 2:

Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.

Alibaba
|
LeetCode

class Solution {
public:
    int pathSum(vector<int>& nums) {
        int res=0;
        unordered_map<int, int> mp;
        for (auto& n:nums) {
            mp[n/10]=n%10;
        }
        dfs(res, mp, nums[0]/10, 0);
        return res;
    }
private:
    void dfs(int& res, unordered_map<int, int>& mp, int root, int curr) {
        int depth=root/10, level=root%10;
        int left=(depth+1)*10+2*level-1, right=(depth+1)*10+2*level;
        curr+=mp[root];
        if (mp.find(left)==mp.end() && mp.find(right)==mp.end()) {
            res+=curr;
            return;
        }
        if (mp.find(left)!=mp.end()) dfs(res, mp, left, curr);
        if (mp.find(right)!=mp.end()) dfs(res, mp, right, curr);
    }
};


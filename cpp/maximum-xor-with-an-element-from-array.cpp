1707. Maximum XOR With an Element From Array
Hard

87

7

Add to List

Share
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
 

Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109

class TrieNode {
public:
    vector<TrieNode*> children;
    TrieNode() { children.resize(2); }
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
        empty=true;
    }
    
    void insert(int num) {
        empty=false;
        auto node=root;
        for (int i=31; i>=0; --i) {
            int b=(num>>i) & 1;
            if (node->children[b]==NULL) node->children[b]=new TrieNode();
            node=node->children[b];
        }
    }
    
    int query(int num) {
        if (empty) return -1;
        auto node=root;
        int res=0;
        for (int i=31; i>=0; --i) {
            int b=(num>>i) & 1;
            if (node->children[b^1]!=NULL) {
                node=node->children[b^1];
                res|=(1<<i);
            } else {
                node=node->children[b];
            }
        }
        
        return res;
    }
private:
    TrieNode* root;
    bool empty;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int m=nums.size(), n=queries.size(), j=0;
        vector<int> res(n, -1);
        sort(nums.begin(), nums.end());
        vector<vector<int>> sortedQueries(n);
        for (int i=0; i<n; ++i) {
            sortedQueries[i]={i, queries[i][0], queries[i][1]};
        }
        sort(sortedQueries.begin(), sortedQueries.end(), [](vector<int>& a, vector<int>& b){ return a[2]<b[2]; });
        auto trie=Trie();
        
        for (auto& q:sortedQueries) {
            while (j<m && nums[j]<=q[2]) {
                trie.insert(nums[j]);
                j++;
            }
            res[q[0]]=trie.query(q[1]);
        }
        return res;
    }
};


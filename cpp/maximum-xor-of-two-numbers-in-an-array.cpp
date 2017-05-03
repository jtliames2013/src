421. Maximum XOR of Two Numbers in an Array Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 11049
Total Submissions: 24851
Difficulty: Medium
Contributors:
shen5630
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
Subscribe to see which companies asked this question.

Hide Tags Bit Manipulation Trie

1. Trie
class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode*> children;
        TrieNode() { children.resize(2); }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root=new TrieNode();
        TrieNode *curr;
        for (auto n:nums) {
            curr=root;
            for (int i=31; i>=0; i--) {
                int b=((n>>i) & 0x1);
                if (curr->children[b]==NULL) {
                    curr->children[b]=new TrieNode();
                }
                curr=curr->children[b];
            }      
        }
        
        int res=0;
        for (auto n:nums) {
            curr=root;
            int sum=0;
            for (int i=31; i>=0; i--) {
                int b=((n>>i) & 0x1);
                if (curr->children[b^1]!=NULL) {
                    sum|=(1<<i);
                    curr=curr->children[b^1];
                } else {
                    curr=curr->children[b];
                }
            }
            res=max(res, sum);
        }
        
        return res;
    }
};

2. Hash set
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0, mask=0;
        for (int i=31; i>=0; i--) {
            unordered_set<int> st;
            mask |= (1<<i);
            for (auto n:nums) st.insert(n & mask);
            
            int tmp = res | (1<<i);
            for (auto prefix:st) {
                if (st.find(prefix ^ tmp)!=st.end()) {
                    res=tmp;
                    break;
                }
            }
        }
        
        return res;
    }
};


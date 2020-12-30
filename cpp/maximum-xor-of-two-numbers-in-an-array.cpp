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

Let us try to build the biggest XOR number binary digit by digit. So, the first question we are going to ask, is there two numbers, 
such that its XOR starts with 1...... (length is 32 bits). Howe we can find it? Let us use the idea of Problem 1: 
TwoSum: put all prefixes of lengh one to set and then try to find two numbers in this set such that their XOR starts with 1 
(at first we have at most 2 elements in our set). Imagine that there are two numbers, which XOR starts with 1......, 
then the next question is there are two numbers with XOR starts with 11....., we again iterate through all numbers and 
find two of them with XOR starts with 11. It can happen that on the next step we did not find XOR starts with 111....., 
then we do not change our ans and on next step we are looking for XOR starts with 1101... and so on.

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
            // get the prefix bits
            for (auto n:nums) st.insert(n & mask);
            
            // set the bit to 1 to check XOR
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


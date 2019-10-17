331. Verify Preorder Serialization of a Binary Tree Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 32601
Total Submissions: 91494
Difficulty: Medium
Contributor: LeetCode
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> stk;
        istringstream iss(preorder);
        string val;
        
        while (getline(iss, val, ',')) {
            if (val=="#") {
                while (!stk.empty() && stk.back()=="#") {
                    stk.pop_back();
                    if (stk.empty()) return false;
                    stk.pop_back();
                }
            }
            stk.push_back(val);
        }
        
        if (stk.size()==1 && stk.back()=="#") return true;
        else return false;
    }
};

2.
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int diff=1;
        istringstream iss(preorder);
        string val;
        while (getline(iss, val, ',')) {
            // use one in degree
            if (--diff<0) return false;
            // create two out degree
            if (val!="#") diff+=2;
        }
        return diff==0;
    }
};

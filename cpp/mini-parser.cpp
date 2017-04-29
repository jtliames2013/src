385. Mini Parser Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 13425
Total Submissions: 44773
Difficulty: Medium
Contributor: LeetCode
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.

Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
Subscribe to see which companies asked this question.

Hide Tags Stack String
Hide Similar Problems (M) Flatten Nested List Iterator (M) Ternary Expression Parser

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
    NestedInteger deserialize(string s) {
        stack<NestedInteger*> stk;
        NestedInteger dummy;
        stk.push(&dummy);
        int num=0;
        bool neg=false;
        for (int i=0; i<s.size();) {
            if (isdigit(s[i])) {
                num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num*=10;
                    num+=s[i]-'0';
                    i++;
                }
                NestedInteger *n=new NestedInteger(neg?-num:num);
                neg=false;
                stk.top()->add(*n);
            } else if (s[i]=='-') {
                neg=true; 
                i++;
            } else if (s[i]=='[') {
                NestedInteger *n=new NestedInteger();
                stk.push(n);
                i++;
            } else if (s[i]==']') {
                NestedInteger *n=stk.top();
                stk.pop();
                // add during pop since the implementation of add creates a copy
                stk.top()->add(*n);
                i++;
            } else if (s[i]==',') {
                i++;
            } else {
                // should not come here
            }
        }
        return stk.top()->getList().front();
    }
};


402. Remove K Digits   QuestionEditorial Solution  My Submissions
Total Accepted: 7607 Total Submissions: 29807 Difficulty: Medium Contributors: Admin
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

Subscribe to see which companies asked this question

Hide Tags Stack Greedy
Hide Similar Problems (H) Create Maximum Number

The first algorithm is straight-forward. Let's think about the simplest case: how to remove 1 digit from the number so that the new number is the smallest possible？ Well, one can simply scan from left to right, and remove the first "peak" digit; the peak digit is larger than its right neighbor. One can repeat this procedure k times, and obtain the first algorithm:
The above algorithm is a bit inefficient because it frequently remove a particular element from a string and has complexity O(k*n).

One can simulate the above procedure by using a stack, and obtain a O(n) algorithm. Note, when the result stack (i.e. res) pop a digit, it is equivalent as remove that "peak" digit.

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (auto c:num) {
            while (!res.empty() && res.back()>c && k>0) {
                res.pop_back();
                k--;
            }
            // no leading '0'
            if (!res.empty() || c!='0') res.push_back(c);
        }
        
        while (!res.empty() && k>0) {
            res.pop_back();
            k--;
        }
        
        return res.empty()?"0":res;
    }
};


1404. Number of Steps to Reduce a Number in Binary Representation to One
Medium

14

5

Add to List

Share
Given a number s in their binary representation. Return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It's guaranteed that you can always reach to one for all testcases.

 

Example 1:

Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
Example 2:

Input: s = "10"
Output: 1
Explanation: "10" corressponds to number 2 in their decimal representation.
Step 1) 2 is even, divide by 2 and obtain 1.  
Example 3:

Input: s = "1"
Output: 0
 

Constraints:

1 <= s.length <= 500
s consists of characters '0' or '1'
s[0] == '1'

1.
class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        if (n==1) return 0;
        if (s[n-1]=='0') {
            s.pop_back();
            return 1+numSteps(s);
        } else {
            int i=n-1;
            for (; i>=0; --i) {
                if (s[i]=='1') s[i]='0';
                else {
                    s[i]='1';
                    break;
                }
            }
            if (i<0) s.insert(s.begin(), '0');
            return 1+numSteps(s);
        }
        return 0;
    }
};

2.
class Solution {
public:
    int numSteps(string s) {
        int res = 0, rem = 0;
        for (; s != "1"; s.pop_back()) {
            if (s.back() - '0' + rem == 1) {
                rem = 1;
                res += 2;
            }
            else
                res += 1;
        }
        return res + rem;
    }
};


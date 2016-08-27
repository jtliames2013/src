7. Reverse Integer  QuestionEditorial Solution  My Submissions
Total Accepted: 158009 Total Submissions: 663437 Difficulty: Easy
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

Hide Company Tags Bloomberg Apple
Hide Tags Math
Hide Similar Problems (E) String to Integer (atoi)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

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

class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0)
        {
        	neg = true;
        	x = 0 - x;
        }

        int n = 0;
        while (x > 0)
        {
        	n *= 10;
        	n += x % 10;
        	x /= 10;
        }

        if (neg) n = 0 - n;
        return n;
    }
};

2.
class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if (x<0) {
            neg=true;
            x=-x;
        }
        
        unsigned long long res=0;
        while (x>0) {
            int digit=x%10;
            res=res*10+digit;
            x/=10;
        }
        if (res>INT_MAX) return 0;
        return neg?-res:res;
    }
};

int main()
{
	return 0;
}


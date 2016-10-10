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
    bool isPalindrome(int x) {
    	if (x == 0) return true;
    	if (x < 0) return false;

    	int div = 1;
    	int t = x;
    	while (t >= 10)
    	{
    		t /= 10;
    		div *= 10;
    	}

    	int l, r;
    	while (x > 0)
    	{
    		l = x / div;
    		r = x % 10;
    		if (l != r) return false;
    		x %= div;
    		x /= 10;
    		div /= 100;
    	}

    	return true;
    }
};

2.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x==0) return true;
        if (x<0) return false;
        long long n=1;
        while (n<=x) n*=10;
        n/=10;
        
        while (x>0) {
            int l=x/n;
            int r=x%10;
            if (l!=r) return false;
            x%=n;
            x/=10;
            n/=100;
        }
        
        return true;
    }
};

int main()
{
	Solution s;
	s.isPalindrome(-2147483648);
	return 0;
}


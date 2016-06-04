nclude <stdio.h>
#include <stdlib.h>
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
	void addSum(char c, bool &inc, string &sum)
	{
		if (c == '0')
		{
			if (inc == false)
			{
				sum.insert(sum.begin(), '0');
			}
			else
			{
				sum.insert(sum.begin(), '1');
				inc = false;
			}
		}
		else
		{
			if (inc == false)
			{
				sum.insert(sum.begin(), '1');
			}
			else
			{
				sum.insert(sum.begin(), '0');
			}
		}
	}

    string addBinary(string a, string b) {
    	string sum;

    	if (a.empty() && b.empty())
    	{
    		return sum;
    	}
    	else if (a.empty())
    	{
    		return b;
    	}
    	else if (b.empty())
    	{
    		return a;
    	}
    	else
    	{
    		bool inc = false;
    		char ca, cb, c;
    		while (!a.empty() && !b.empty())
    		{
    			ca = *(a.end() - 1);
    			cb = *(b.end() - 1);

    			if (ca == '0' && cb =='0')
    			{
    				if (inc == false)
    				{
    					sum.insert(sum.begin(), '0');
    				}
    				else
    				{
    					sum.insert(sum.begin(), '1');
    					inc = false;
    				}
    			}
    			else if (ca == '0' || cb == '0')
    			{
    				if (inc == false)
    				{
    					sum.insert(sum.begin(), '1');
    				}
    				else
    				{
    					sum.insert(sum.begin(), '0');
    				}
    			}
    			else
    			{
    				if (inc == false)
    				{
    					sum.insert(sum.begin(), '0');
    					inc = true;
    				}
    				else
    				{
    					sum.insert(sum.begin(), '1');
    				}
    			}

    			a.erase(a.end() - 1);
    			b.erase(b.end() - 1);
    		}

    		if (!a.empty())
    		{
    			while (!a.empty())
    			{
    				c = *(a.end() - 1);

    				addSum(c, inc, sum);
    				a.erase(a.end() - 1);
    			}
    		}
    		else if (!b.empty())
    		{
    			while (!b.empty())
				{
					c = *(b.end() - 1);

					addSum(c, inc, sum);
					b.erase(b.end() - 1);
				}
    		}

			if (inc == true)
			{
				sum.insert(sum.begin(), '1');
			}

    		return sum;
    	}
    }
};

2. 
class Solution {

public:

    string addBinary(string a, string b) {

        string res;

        int sizea=a.size();

        int sizeb=b.size();

        int i=sizea-1, j=sizeb-1;

        bool carry=false;

        int num;

        while (i>=0 || j>=0) {

            if (i>=0 && j>=0) {

                num=a[i]-'0'+b[j]-'0';

                i--;

                j--;

            } else if (i>=0) {

                num=a[i]-'0';

                i--;

            } else if (j>=0) {

                num=b[j]-'0';

                j--;

            }

            if (carry) {

                num++;

                carry=false;

            }

            if (num>1) carry=true;

            num%=2;

            res.insert(res.begin(), num+'0');

        }

        

        if (carry) {

            res.insert(res.begin(), '1');

        }

        return res;

    }

};


int main()
{
	return 0;
}


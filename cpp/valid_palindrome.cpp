#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
	bool areCharsEqual(char a, char b)
	{
		if (a == b || a == b + 32 || a == b - 32)
			return true;
		else
			return false;
	}

	bool isAlphaNumeric(char a)
	{
		if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9'))
			return true;
		else
			return false;
	}

    bool isPalindrome(string s) {
    	if (s.empty()) return true;
    	int i=0;
    	int j=s.length()-1;

    	while (i <= j)
    	{
    		if (!isAlphaNumeric(s[i]))
    		{
    			i++;
    			continue;
    		}

    		if (!isAlphaNumeric(s[j]))
    		{
    			j--;
    			continue;
    		}

    		if (areCharsEqual(s[i], s[j]))
    		{
    			i++;
    			j--;
    		}
    		else
    		{
    			return false;
    		}
    	}
    	return true;
    }
};

int main()
{
	Solution s;
	bool b = s.isPalindrome("abccba");

	return 0;
}


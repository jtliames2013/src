125. Valid Palindrome  QuestionEditorial Solution  My Submissions
Total Accepted: 123277 Total Submissions: 496004 Difficulty: Easy
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Subscribe to see which companies asked this question

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

2.
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0, r=n-1;
        while (l<r) {
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else {
                if (tolower(s[l])!=tolower(s[r])) return false;
                l++;
                r--;
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


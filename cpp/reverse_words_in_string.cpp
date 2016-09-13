151. Reverse Words in a String  QuestionEditorial Solution  My Submissions
Total Accepted: 112874 Total Submissions: 715351 Difficulty: Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
Hide Company Tags Microsoft Snapchat Apple Bloomberg Yelp
Hide Tags String
Hide Similar Problems (M) Reverse Words in a String II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	void swap(string &s, int l, int r)
	{
		char temp;
		while (l < r)
		{
			temp = s[l];
			s[l] = s[r];
			s[r] = temp;
			l++;
			r--;
		}
	}

	bool isSpace(char c)
	{
		return (c == ' ' || c == '\t');
	}

    void reverseWords(string &s) {
    	int len = s.size();
    	if (len == 0) return;

    	swap(s, 0, len - 1);

    	bool foundStart = false;
    	int l;
    	for (int i = 0; i < len; i++)
    	{
    		if (!isSpace(s[i]) && foundStart == false)
    		{
    			foundStart = true;
    			l = i;
    		}
    		else if (isSpace(s[i]) && foundStart == true)
    		{
    			foundStart = false;
    			swap(s, l, i - 1);
    		}
    	}

    	if (foundStart == true)
    	{
    		swap(s, l, len - 1);
    	}

    	int start = 0;
    	bool leading = true;
    	bool hasSpace = false;
    	for (int i = 0; i < len; i++)
    	{
    		if (leading == true && !isSpace(s[i]))
    		{
    			leading = false;
    			s[start] = s[i];
    			start++;
    		}
    		else if (!isSpace(s[i]))
    		{
    			s[start] = s[i];
    			start++;
    			hasSpace = false;
    		}
    		else if (leading == false && isSpace(s[i]) && hasSpace == false)
    		{
    			hasSpace = true;
    			s[start] = s[i];
    			start++;
    		}
    	}

    	if (isSpace(s[start-1]))
		{
    		s[start-1] = '\0';
    		s.resize(start-1);
		}
    	else
    	{
    		s[start] = '\0';
    		s.resize(start);
    	}
    }
};

2.
class Solution {
public:
    void reverse(string &s, int start, int end) {
        while (start<end) {
            char tmp=s[start];
            s[start]=s[end];
            s[end]=tmp;
            start++;
            end--;
        }
    }

    void reverseWords(string &s) {
        int size=s.size();
        reverse(s, 0, size-1);        
        bool started=false;
        int startIdx=0;
        for (int i=0; i<size; i++) {
            if (s[i]==' ') {
                if (started) {
                    reverse(s, startIdx, i-1);
                    started=false;
                }
            } else {
                if (!started) {
                    started=true;
                    startIdx=i;
                }
            }
        }
        
        if (started) {
            reverse(s, startIdx, size-1);
        }
        
        while (*s.begin()==' ') s.erase(s.begin());
        while (s.back()==' ') s.pop_back();
       
        int end=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]!=' ' || s[i-1]!=' ') {
                s[end]=s[i];
                end++;
            }
        }
        
        s.resize(end);
    }

};

3.
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        for (size_t i=0; i<s.size();) {
            if (s[i]==' ') {
                i++;
            } else {
                int start=i;
                while (i<s.size() && s[i]!=' ') {
                    i++;
                }
                reverse(s.begin()+start, s.begin()+i);
            }
        }
        
        int end=0;
        int i=0;
        while (i<s.size() && s[i]==' ') i++;
        
        for (; i<s.size(); i++) {
            if (s[i]!=' ' || (i>0 && s[i-1]!=' ')) {
                if (end!=i) {
                    s[end]=s[i];
                }
                end++;
            }
        }
        end--;
        while (end>=0 && s[end]==' ') end--;
        s.resize(end+1);
    }
};

int main()
{
	return 0;
}


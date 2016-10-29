273. Integer to English Words 
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

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

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	string getOne(int num) {
		switch (num) {
		case 1:
			return "One";
		case 2:
			return "Two";
		case 3:
			return "Three";
		case 4:
			return "Four";
		case 5:
			return "Five";
		case 6:
			return "Six";
		case 7:
			return "Seven";
		case 8:
			return "Eight";
		case 9:
			return "Nine";
		}
	}

	string getTen(int num) {
		switch (num) {
		case 2:
			return "Twenty";
		case 3:
			return "Thirty";
		case 4:
			return "Forty";
		case 5:
			return "Fifty";
		case 6:
			return "Sixty";
		case 7:
			return "Seventy";
		case 8:
			return "Eighty";
		case 9:
			return "Ninety";
		}
	}

	string getOneTen(int num) {
		switch (num) {
		case 10:
			return "Ten";
		case 11:
			return "Eleven";
		case 12:
			return "Twelve";
		case 13:
			return "Thirteen";
		case 14:
			return "Fourteen";
		case 15:
			return "Fifteen";
		case 16:
			return "Sixteen";
		case 17:
			return "Seventeen";
		case 18:
			return "Eighteen";
		case 19:
			return "Nineteen";
		}
	}

	string convertThreeDigit(int num) {
		string res;
		bool appendSpace=false;
		int digit=num/100;
		if (digit>0) {
			res.append(getOne(digit));
			res.append(" Hundred");
			appendSpace=true;
		}
		num=num%100;
		digit=num/10;
		if (digit==1) {
			if (appendSpace) res.append(" ");
			res.append(getOneTen(num));
		} else {
			if (digit>0) {
				if (appendSpace) res.append(" ");
				res.append(getTen(digit));
				appendSpace=true;
			}
			num=num%10;
			if (num>0) {
				if (appendSpace) res.append(" ");
				res.append(getOne(num));
			}
		}

		return res;
	}

    string numberToWords(int num) {
    	string res;
    	bool appendSpace=false;
    	int part=num/1000000000;
    	if (part>0) {
    		res.append(convertThreeDigit(part));
    		res.append(" Billion");
    		appendSpace=true;
    	}
    	num=num%1000000000;
    	part=num/1000000;
    	if (part>0) {
    		if (appendSpace) res.append(" ");
    		res.append(convertThreeDigit(part));
    		res.append(" Million");
    		appendSpace=true;
    	}
    	num=num%1000000;
    	part=num/1000;
    	if (part>0) {
    		if (appendSpace) res.append(" ");
    		res.append(convertThreeDigit(part));
    		res.append(" Thousand");
    		appendSpace=true;
    	}
    	num=num%1000;
    	if (num>0) {
    		if (appendSpace) res.append(" ");
    		res.append(convertThreeDigit(num));
    	} else {
    		if (appendSpace==false) res.append("Zero");
    	}

    	return res;
    }
};

2.

class Solution {
public:
	string getOne(int num) {
		switch (num) {
		case 1:
			return "One";
		case 2:
			return "Two";
		case 3:
			return "Three";
		case 4:
			return "Four";
		case 5:
			return "Five";
		case 6:
			return "Six";
		case 7:
			return "Seven";
		case 8:
			return "Eight";
		case 9:
			return "Nine";
		default:
		    return "";
		}
	}

	string getTen(int num) {
		switch (num) {
		case 2:
			return "Twenty";
		case 3:
			return "Thirty";
		case 4:
			return "Forty";
		case 5:
			return "Fifty";
		case 6:
			return "Sixty";
		case 7:
			return "Seventy";
		case 8:
			return "Eighty";
		case 9:
			return "Ninety";
		default:
		    return "";
		}
	}

	string getOneTen(int num) {
		switch (num) {
		case 10:
			return "Ten";
		case 11:
			return "Eleven";
		case 12:
			return "Twelve";
		case 13:
			return "Thirteen";
		case 14:
			return "Fourteen";
		case 15:
			return "Fifteen";
		case 16:
			return "Sixteen";
		case 17:
			return "Seventeen";
		case 18:
			return "Eighteen";
		case 19:
			return "Nineteen";
		default:
		    return "";
		}
	}

    string getScale(int scale) {
        if (scale==1000000000) return "Billion";
        else if (scale==1000000) return "Million";
        else if (scale==1000) return "Thousand";
        else return "";
    }
    
    string convertThreeDigit(int part) {
        string res;
        int digit=part/100;
        if (digit>0) {
            res+=getOne(digit)+" Hundred";
        }
        part%=100;
        digit=part/10;
        if (digit>0) {
            if (res.size()>0) res+=" ";
            if (digit==1) {
                res+=getOneTen(part);
                return res;
            } else {
                res+=getTen(digit);
            }
        }
        
        part%=10;
        if (part>0) {
            if (res.size()>0) res+=" ";
            res+=getOne(part);
        }
        
        return res;
    }
    
    string numberToWords(int num) {
        int scale=1000000000;
        int part;
        string res;
        
        while (scale>0) {
            int part=num/scale;
            if (part>0) {
                if (res.size()>0) res+=" ";
                res+=convertThreeDigit(part);
                if (scale>1) res+=" " + getScale(scale);
            }
            
            num%=scale;
            scale/=1000;
        }
        
        if (num==0 && res.size()==0) res+="Zero";
        
        return res;
    }
};

2.
class Solution {
public:
    string convert(int part) {
        if (part==0) return "";
        else if (part<20) {
            return underTwenty[part];
        } else if (part<100) {
            return tens[part/10] + " " + underTwenty[part%10];
        } else {
            return underTwenty[part/100] + " Hundred " + convert(part%100);
        }
    }
    string numberToWords(int num) {
        string res;
        if (num==0) return "Zero";
        int i=0;
        int scale=1000000000;
        while (num>0) {
            int part=num/scale;
            if (part>0) {
                if (!res.empty()) res+=" ";
                res+=convert(part);
                if (res[res.size()-1]==' ') res.pop_back();
                if (scale>1) res+=" " + thousands[i];
            }
            num%=scale;
            scale/=1000;
            i++;
        }
        
        return res;
    }
private:
    vector<string> thousands={"Billion", "Million", "Thousand"};
    vector<string> underTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};

int main()
{
	return 0;
}


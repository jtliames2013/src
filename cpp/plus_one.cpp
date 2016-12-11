66. Plus One 
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Hide Company Tags Google
Hide Tags Array Math
Hide Similar Problems (M) Multiply Strings (E) Add Binary (M) Plus One Linked List

#include <stdio.h>
#include <vector>
#include <queue>


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for (int i=n-1; i>=0; i--) {
            if (digits[i]<9) {
                digits[i]++;
                return digits;
            } else {
                digits[i]=0;
            }
        }
        
        digits.insert(digits.begin(),1);
        return digits;
    }
};

2.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int size=digits.size();
        if (size==0) return res;
        bool carry=false;
        int num;
        for (int i=size-1; i>=0; i--) {
            num=digits[i];
            if (i==size-1) num++;
            if (carry) num++;
            if (num>=10) {
                num%=10;
                carry=true;
            } else {
                carry=false;
            }
            res.insert(res.begin(), num);
        }
        
        if (carry) res.insert(res.begin(), 1);
        
        return res;
    }
};

int main()
{
	return 0;
}


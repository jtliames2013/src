400. Nth Digit   QuestionEditorial Solution  My Submissions
Total Accepted: 8702 Total Submissions: 28877 Difficulty: Easy Contributors: Admin
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
Subscribe to see which companies asked this question

Hide Tags Math

1 digit - 9
2 digit - 90
3 digit - 900
...

class Solution {
public:
    int findNthDigit(int n) {
        int len=1;
        long count=9;
        int num=1;
        while (n>count*len) {
            n-=count*len;
            count*=10;
            len++;
            num*=10;
        }
        
        num+=(n-1)/len;
        
        string str=to_string(num);
        return str[(n-1)%len]-'0';
    }
};


984. String Without AAA or BBB
Easy

59

113

Favorite

Share
Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 

Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: A = 4, B = 1
Output: "aabaa"
 

Note:

0 <= A <= 100
0 <= B <= 100
It is guaranteed such an S exists for the given A and B.

1.
class Solution {
public:
    string strWithout3a3b(int A, int B, char a='a', char b='b') {
        if (A<B) return strWithout3a3b(B, A, 'b', 'a');
        string res;
        if (A>=2*B) {
            for (int i=0; i<B; ++i) res+=string(2,a)+string(1,b);
            for (int i=0; i<A-2*B; ++i) res+=string(1,a);
        } else {
            for (int i=0; i<A-B; ++i) res+=string(2,a)+string(1,b);
            for (int i=0; i<2*B-A; ++i) res+=string(1,a)+string(1,b);
        }
        return res;
    }
};

2.
class Solution {
public:
    string strWithout3a3b(int A, int B, char a='a', char b='b') {
        if (A<B) return strWithout3a3b(B, A, 'b', 'a');
        string res;
        while (A-- > 0) {
            res+=a;
            if (A>B) {
                res+=a;
                A--;
            }
            if (B>0) {
                res+=b;
                B--;
            }
        }
        return res;
    }
};

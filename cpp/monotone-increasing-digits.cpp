738. Monotone Increasing Digits
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str=to_string(N);
        int pos=str.size();
        for (int i=str.size()-1; i>0; i--) {            
            if (str[i]<str[i-1]) {
                pos=i;
                str[i-1]--;
            }
        }
        for (int i=pos; i<str.size(); i++) str[i]='9';
        return stoi(str);
    }
};

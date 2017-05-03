423. Reconstruct Original Digits from English Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 9063
Total Submissions: 20990
Difficulty: Medium
Contributor: LeetCode
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
Subscribe to see which companies asked this question.

Hide Tags Math

The even digits all have a unique letter while the odd digits all don't:

zero: Only digit with z
two: Only digit with w
four: Only digit with u
six: Only digit with x
eight: Only digit with g

The odd ones for easy looking, each one's letters all also appear in other digit words:
one, three, five, seven, nine

class Solution {
public:
    string originalDigits(string s) {
        string res;
        vector<int> count(10);
        for (auto c:s) {
            if (c == 'z') count[0]++;
            else if (c == 'w') count[2]++;
            else if (c == 'u') count[4]++; 
            else if (c == 'x') count[6]++;
            else if (c == 'g') count[8]++;
            else if (c == 'h') count[3]++; //3-8            
            else if (c == 'f') count[5]++; //5-4
            else if (c == 's') count[7]++; //7-6
            else if (c == 'i') count[9]++; //9-8-5-6
            else if (c == 'o') count[1]++; //1-0-2-4            
        }
        count[7] -= count[6];
        count[5] -= count[4];
        count[3] -= count[8];
        count[9] = count[9] - count[8] - count[5] - count[6];
        count[1] = count[1] - count[0] - count[2] - count[4];
        
        for (int i=0; i<10; i++) {
            for (int j=0; j<count[i]; j++) {
                res+=i+'0';
            }
        }
        return res;
    }
};


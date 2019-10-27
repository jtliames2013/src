166. Fraction to Recurring Decimal
DescriptionHintsSubmissionsSolutions
Total Accepted: 50442
Total Submissions: 292148
Difficulty: Medium
Contributor: LeetCode
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.

Subscribe to see which companies asked this question.

Hide Tags Hash Table Math

Well, the key to this problem is on how to identify the recurring parts. After doing some examples using pen and paper, you may find that for the decimal parts to recur, the remainders should recur. So we need to maintain the remainders we have seen. Once we see a repeated remainder, we know that we have reached the end of the recurring parts and should enclose it with a ). However, we still need to insert the ( to the correct position. So we maintain a mapping from each remainder to the position of the corresponding quotient digit of it in the recurring parts. Then we use this mapping to retrieve the starting position of the recurring parts.

Now we have solved the trickiest part of this problem.

There are some remaining problems to solve to achieve a bug-free solution.

Pay attention to the sign of the result;
Handle cases that may cause overflow like numerator = -2147483648, denominator = -1 appropriately by using long long;
Handle all the cases of (1) no fractional part; (2) fractional part does not recur; and (3) fractional part recurs respectively.
To handle problem 3, we divide the division process into the integral part and the fractional part. For the fractional part, if it does not recur, then the remainder will become 0 at some point and we could return. If it does recur, the method metioned in the first paragraph has already handled it.

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = abs((long)numerator);
        long denom = abs((long)denominator);
        long integral = numer / denom;
        res += to_string(integral);
        long remain = numer % denom;
        if (!remain) return res;
        
        res += '.';
        remain *= 10;
        unordered_map<long, long> mp; 
        while (remain) {
            if (mp.find(remain) != mp.end()) { 
                res.insert(mp[remain], 1, '(');
                res += ')';
                break;
            }
            long quotient = remain / denom;
            mp[remain] = res.size();
            res += to_string(quotient);
            remain = (remain % denom) * 10;
        }
        return res;
    }
};

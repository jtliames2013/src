306. Additive Number Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 22828
Total Submissions: 83841
Difficulty: Medium
Contributor: LeetCode
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

class Solution {
public:
    bool isValid(string s) {
        return s.size()==1 || s[0]!='0';
    }
    
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for (int i=0; i<(n+1)/2; i++) {
            for (int j=i+1; j<n && j-i<=n/2; j++) {
                string s1=num.substr(0,i+1);
                string s2=num.substr(i+1, j-i);
                if (!isValid(s1) || !isValid(s2)) continue;
                
                unsigned long long a=stoull(s1), b=stoull(s2), c;
                int start=j+1;
                while (1) {
                    c=a+b;
                    string s3=to_string(c);
                    int len=s3.size();
                    if (start+len>n || s3!=num.substr(start, len)) break;
                    a=b;
                    b=c;
                    start+=len;
                    if (start==n) return true;
                }
            }
        }
        return false;
    }
};


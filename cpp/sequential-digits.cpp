1291. Sequential Digits
Medium

71

8

Add to List

Share
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9

F5 Networks
|
LeetCode

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> q;
        for (int i=1; i<=9; ++i) q.push(i);
        
        while (!q.empty()) {
            auto f=q.front();
            q.pop();
            if (f>=low && f<=high) res.push_back(f);
            if (f>high) break;
            if (f%10<9) q.push(f*10+f%10+1);
        }
        return res;
    }
};


179. Largest Number  QuestionEditorial Solution  My Submissions
Total Accepted: 54991 Total Submissions: 268383 Difficulty: Medium
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Sort

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> v;
        for (auto n:nums) v.push_back(to_string(n));
        
        sort(v.begin(), v.end(), [](string& a, string& b) {return a+b>b+a; });
        for (auto s:v) res+=s;
        while (res.size()>1 && res[0]=='0') res.erase(res.begin());
        
        return res;
    }
};


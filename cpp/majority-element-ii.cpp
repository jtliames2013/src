229. Majority Element II  
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
Hide Company Tags Zenefits
Hide Tags Array
Hide Similar Problems (E) Majority Element

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n1=0, n2=0, c1=0, c2=0;
        for (auto n:nums) {
            if (n==n1) c1++;
            else if (n==n2) c2++;
            else if (c1==0) {
                n1=n;
                c1++;
            } else if (c2==0) {
                n2=n;
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        
        c1=c2=0;
        for (auto n:nums) {
            if (n==n1) c1++;
            else if (n==n2) c2++;
        }
        
        if (c1>nums.size()/3) res.push_back(n1);
        if (c2>nums.size()/3) res.push_back(n2);
        return res;
    }
};


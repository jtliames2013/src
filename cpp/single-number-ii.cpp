137. Single Number II  QuestionEditorial Solution  My Submissions
Total Accepted: 94790 Total Submissions: 242820 Difficulty: Medium
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

Hide Tags Bit Manipulation
Hide Similar Problems (E) Single Number (M) Single Number III

1.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        vector<int> count(32);
        
        for (auto& n:nums) {
            for (int i=0; i<32; ++i) {
                count[i]+=((n>>i)&0x1);
            }
        }
        for (int i=0; i<32; ++i) {
            if (count[i]%3!=0) res|=(1<<i);
        }
        return res;
    }
};

2.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1=0, x2=0, mask=0;
         
        for (int i:nums) {
            x2^=x1 & i;
            x1^=i;
            mask=~(x1 & x2);
            x2&=mask;
            x1&=mask;
        }

        return x1;      
    }
};


You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

class Solution {
public:
    double calc(double a, double b, char op) {
        switch (op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
            default: return 0;
        }
    }
    
    unordered_set<double> gen(vector<double> nums, int start, int end) {
        unordered_set<double> st;
        if (start==end) {
            st.insert(nums[start]);
            return st;
        }
        
        for (int i=start; i<end; i++) {
            unordered_set<double> left=gen(nums, start, i);
            unordered_set<double> right=gen(nums, i+1, end);
            for (auto l:left) {
                for (auto r:right) {
                    for (int k=0; k<4; k++) {
                        if (r==0 && op[k]=='/') continue;
                        st.insert(calc(l, r, op[k]));
                    }
                }
            }
        }
        return st;
    }
    
    bool judge(vector<double> nums) {        
        unordered_set<double> st=gen(nums, 0, nums.size()-1);        
        for (auto d:st) {
            if (abs(d-24)<0.0001) return true;
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> db(nums.size());
        for (int i=0; i<nums.size(); i++) db[i]=nums[i];
        sort(db.begin(), db.end());
        do {
            if (judge(db)) return true;
        } while (next_permutation(db.begin(), db.end()));
        return false;
    }
private:    
    const char op[4]={'+', '-', '*', '/'};    
};

2.
class Solution {
public:
    double calc(double a, double b, char op) {
        switch (op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
            default: return 0;
        }
    }
    
    bool judge(vector<double> nums) {
        if (nums.size()==1) {
            return abs(nums[0]-24)<0.001;
        }
        
        vector<double> next(nums.size()-1);        
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size(); j++) {
                int idx=0;
                for (int k=0; k<nums.size(); k++) {
                    if (k!=i && k!=j) next[idx++]=nums[k];
                }
                
                for (int k=0; k<4; k++) {
                    if (nums[j]==0 && op[k]=='/') continue;
                    next[next.size()-1]=calc(nums[i], nums[j], op[k]);
                    if (judge(next)) return true;
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> db(nums.size());
        for (int i=0; i<nums.size(); i++) db[i]=nums[i];
        sort(db.begin(), db.end());
        do {
            if (judge(db)) return true;
        } while (next_permutation(db.begin(), db.end()));
        return false;
    }
private:    
    const char op[4]={'+', '-', '*', '/'};    
};


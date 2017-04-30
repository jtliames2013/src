386. Lexicographical Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 4158 Total Submissions: 13034 Difficulty: Medium
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

Subscribe to see which companies asked this question

class Solution {
public:
    void dfs(vector<int>& res, int n, int curr) {
        if (curr>n) return;
        res.push_back(curr);
        for (int i=0; i<=9; i++) {
            dfs(res, n, curr*10+i);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i=1; i<=9; i++) {
            dfs(res, n, i);
        }
        return res;
    }
};

2. Iteratively
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr=1;
        while (1) {
            res.push_back(curr);
            if(curr*10<=n) {
                curr*=10;
            } else if (curr%10<9 && curr+1<=n) {
                curr++;
            } else {
                curr/=10;
                while ((curr)%10==9) curr/=10;
                if (curr==0) break;
                curr++;
            }
        }
        
        return res;
    }
};


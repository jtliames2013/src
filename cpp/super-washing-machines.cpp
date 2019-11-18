517. Super Washing Machines Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 2854
Total Submissions: 7965
Difficulty: Hard
Contributors:
fallcreek
You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation: 
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
3rd move:    2     1 <-- 3    =>    2     2     2   
Example2

Input: [0,3,0]

Output: 2

Explanation: 
1st move:    0 <-- 3     0    =>    1     2     0    
2nd move:    1     2 --> 0    =>    1     1     1     
Example3

Input: [0,2,0]

Output: -1

Explanation: 
It's impossible to make all the three washing machines have the same number of dresses. 
Note:
The range of n is [1, 10000].
The range of dresses number in a super washing machine is [0, 1e5].
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Math

avg [-4, 4, 6, -2, -4]
avg [-3, 4, 6, -3, -4]


class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        if (n==0) return 0;
        int res=0, sum=0;
        for (auto m:machines) sum+=m;
        if (sum%n!=0) return -1;
        int avg=sum/n, balance=0;
        for (auto m:machines) {
            balance+=m-avg;
            res=max({res, abs(balance), m-avg});
        }
        return res;
    }
};

2.
For a single machine, necessary operations is to transfer dresses from one side to another until sum of both sides and itself reaches the average number. We can calculate (required dresses) - (contained dresses) of each side as L and R:

L > 0 && R > 0: both sides lacks dresses, and we can only export one dress from current machines at a time, so result is abs(L) + abs(R)
L < 0 && R < 0: both sides contains too many dresses, and we can import dresses from both sides at the same time, so result is max(abs(L), abs(R))
L < 0 && R > 0 or L >0 && R < 0: the side with a larger absolute value will import/export its extra dresses from/to current machine or other side, so result is max(abs(L), abs(R))

For example, [1, 0, 5], average is 2
for 1, L = 0 * 2 - 0 = 0, R = 2 * 2 - 5= -1, result = 1
for 0, L = 1 * 2 - 1= 1, R = 1 * 2 - 5 = -3, result = 3
for 5, L = 2 * 2 - 1= 3, R = 0 * 2 - 0= 0, result = 3
so minium moves is 3

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        if (n==0) return 0;
        int res=0;
        vector<int> sum(n+1);
        for (int i=1; i<=n; i++) sum[i]=sum[i-1]+machines[i-1];
        if (sum[n]%n!=0) return -1;
        int avg=sum[n]/n;
        for (int i=0; i<n; i++) {
            int l=i*avg-sum[i];
            int r=(n-i-1)*avg-(sum[n]-sum[i]-machines[i]);
            if (l>0 && r>0) {
                res=max(res, abs(l)+abs(r));
            } else {
                res=max(res, max(abs(l), abs(r)));
            }
        }

        return res;
    }
};



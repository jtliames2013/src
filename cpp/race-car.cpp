818. Race Car
DescriptionHintsSubmissionsDiscussSolution
Your car starts at position 0 and speed +1 on an infinite number line.  (Your car can go into negative positions.)

Your car drives automatically according to a sequence of instructions A (accelerate) and R (reverse).

When you get an instruction "A", your car does the following: position += speed, speed *= 2.

When you get an instruction "R", your car does the following: if your speed is positive then speed = -1 , otherwise speed = 1.  (Your position stays the same.)

For example, after commands "AAR", your car goes to positions 0->1->3->3, and your speed goes to 1->2->4->-1.

Now for some target position, say the length of the shortest sequence of instructions to get there.

Example 1:
Input: 
target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0->1->3.
Example 2:
Input: 
target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0->1->3->7->7->6.
 

Note:

1 <= target <= 10000.


DP solution works by noting that after each reverse, the car's speed returns to 1 (the sign can be interpreted as the direction of the speed). So we can redefine the problem in terms of the position of the car while leave out the speed: let T(i) be the length of the shortest instructions to move the car from position 0 to position i, with initail speed of 1 and its direction pointing towards position i. Then our original problem will be T(target), and the base case is T(0) = 0. Next we need to figure out the recurrence relations for T(i).

Note that to apply the definition of T(i) to subproblems, the car has to start with speed of 1, which implies we can only apply T(i) right after the reverse instruction. Also we need to make sure the direction of the initial speed when applying T(i) is pointing towards the final target position.

However, we don't really know how many accelerate instructions there should be before the reverse instruction, so theoretically we need to try all possible cases: zero A, one A, two A, three A, ... and so on. For each case, we can obtain the position of the car right before the reverse instruction, which will be denoted as j = 2^m - 1, with m the number of A's. Then depending on the relation between i and j, there will be three cases:

j < i: the reverse instruction is issued before the car reaches i. In this case, we cannot apply the definition of T(i) to the subproblems directly, because even though the speed of the car returns to 1, its direction is pointing away from the target position (in this case position i). So we have to wait until the second reverse instruction is issued. Again, we don't really know how many accelerate instructions there should be in between these two reverse instructions, so we will try each of the cases: zero A, one A, two A, three A, ..., etc. Assume the number of A is q, then the car will end up at position j - p right before the second reverse instruction, where p = 2^q - 1. Then after the second reverse instruction, our car will start from position j - p with speed of 1 and its direction pointing towards our target position i. Since we want the length of the total instruction sequence to be minimized, we certainly wish to use minimum number of instructions to move the car from j - p to i, which by definition will be given by T(i-(j-p)) (note that in the definition of T(i), we move the car from position 0 to position i. If the start position is not 0, we need to shift both the start and target positions so that the start position is aligned with 0). So in summary, for this case, the total length of the instruction will be given by: m + 1 + q + 1 + T(i-(j-p)), where m is the number of A before the first R, q is the number of A before the second R, the two 1's correspond to the two R's, and lastly T(i-(j-p)) is the length of instructions moving the car from position j - p to the target position i.

j == i: the target position is reached without any reverse instructions. For this case, the total length of the instruction will be given by m.

j > i: the reverse instruction is issued after the car goes beyond i. In this case, we don't need to wait for a second reverse instruction, because after the first reverse instruction, the car's speed returns to 1 and its direction will be pointing towards our target position i. So we can apply the definition of T(i) directly to the subproblem, which will be T(j-i). Note that not only do we need to shift the start and target positions, but also need to swap them as well as the directions. So for this case, the total length of the instructions will be given by m + 1 + T(j-i).

Our final answer for T(i) will be the minimum of the above three cases.


class Solution {
public:
    int dfs(vector<int>& dp, int dist) {
        if (dp[dist]>0) return dp[dist];
        
        int d=dist, n=0;
        while (d) { d>>=1; n++; }
        if ((1<<n)==dist+1) dp[dist]=n;
        else {
            dp[dist]=dfs(dp, (1<<n)-1-dist)+n+1;
            for (int i=0; i<n-1; ++i) {
                dp[dist]=min(dp[dist], dfs(dp, dist-(1<<(n-1))+(1<<i))+n+i+1);
            }
        }
        return dp[dist];
    }
    
    int racecar(int target) {
        if (target<0) return 0;
        vector<int> dp(target+1);
        return dfs(dp, target);
    }
};

964. Least Operators to Express Number
Hard

122

40

Favorite

Share
Given a single positive integer x, we will write an expression of the form x (op1) x (op2) x (op3) x ... where each operator op1, op2, etc. is either addition, subtraction, multiplication, or division (+, -, *, or /).  For example, with x = 3, we might write 3 * 3 / 3 + 3 - 3 which is a value of 3.

When writing such an expression, we adhere to the following conventions:

The division operator (/) returns rational numbers.
There are no parentheses placed anywhere.
We use the usual order of operations: multiplication and division happens before addition and subtraction.
It's not allowed to use the unary negation operator (-).  For example, "x - x" is a valid expression as it only uses subtraction, but "-x + x" is not because it uses negation.
We would like to write an expression with the least number of operators such that the expression equals the given target.  Return the least number of operators used.

 

Example 1:

Input: x = 3, target = 19
Output: 5
Explanation: 3 * 3 + 3 * 3 + 3 / 3.  The expression contains 5 operations.
Example 2:

Input: x = 5, target = 501
Output: 8
Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.  The expression contains 8 operations.
Example 3:

Input: x = 100, target = 100000000
Output: 3
Explanation: 100 * 100 * 100 * 100.  The expression contains 3 operations.
 

Note:

2 <= x <= 100
1 <= target <= 2 * 10^8

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        if (x==target) return 0;
        else if (x>target) {
            // At this time, you can get target either by add target times x/x or subtract (x - target) times x/x to x
	    // For example, x = 3, target = 2. Then, 3/3 + 3/3 or 3 - 3/3 is possible result
            return min(target*2-1, (x-target)*2);
        }
        
        long long sum=x;
        int res=0;
        while (sum<target) {
            // this is gready, put as much as possible 'x'
            res++;
            sum*=x;
        }
        
        if (sum==target) return res;
        
        // when you have remainder, you have two choices, one is add, the other is subtract
	// for example, x = 3, target = 5. Then, 5 = 3 + 2 or 5 = 9 - 4
        int l=INT_MAX, r=INT_MAX;
        if (sum-target<target) {
            // substract
            l=leastOpsExpressTarget(x, sum-target)+res;
        }
        
        // add
        r=leastOpsExpressTarget(x, target-sum/x)+res-1;
        return min(l, r)+1;
    }
};

Approach 1: Dynamic Programming
Intuition

First, we notice that we can consider blocks of multiplication and division separately. Each block is a power of x: either x / x, x, x * x, x * x * x, x * x * x * x and so on. (There is no point to write expressions like x * x / x because it uses strictly more operators.)

Let's think of the cost of a block as all the operators needed to express it, including the addition or subtraction operator in front of it. For example, we can think of x * x + x + x / x as (+ x * x) (+ x) (+ x / x) for a cost of 2 + 1 + 2, minus 1 for the leading + (so the total cost is 4).

We can write the cost of writing a block that has value x^ex 
e
 : it is ee, except when e = 0e=0 it is 2. We want the sum of the costs of all blocks minus 1.

Now, we have the reduced problem: we have the costs of writing all x^ex 
e
  or -x^e−x 
e
 , and we want to find the least cost to express the target.

Notice that modulo xx, the only blocks that change the expression are x^0x 
0
 . Let r_1 = \text{target} \pmod xr 
1
​	
 =target(modx). So we must either subtract r_1r 
1
​	
  x^0x 
0
 's, or add x-r_1x−r 
1
​	
  x^0x 
0
 's. This will form a new "remaining" target, \text{target}_2target 
2
​	
 , that is divisible by xx.

Then, modulo x^2x 
2
 , the only blocks that change the expression are x^1x 
1
  and x^0x 
0
 . However, since the new target is divisible by xx, there is no point to use x^0x 
0
 , as we would have to use at least xx of them to do the same work as one use of x^1x 
1
 , which is a strictly higher cost.

Again, in a similar way, we have r_2 = \text{target}_2 \pmod {x^2}r 
2
​	
 =target 
2
​	
 (modx 
2
 ), and we must either subtract r_2 / xr 
2
​	
 /x x^1x 
1
 's, or add x - r_2 / xx−r 
2
​	
 /x x^1x 
1
 's. This will form a new remaining target \text{target}_3target 
3
​	
 , and so on.

As a concrete example, say x = 5, target = 123. We either add 2 or subtract 3. This leaves us with a target of 120 or 125. If the target is 120, we can either add 5 or subtract 20, leaving us with a target of 100 or 125. If the target is 100, we can either add 25 or subtract 100, leaving us with a target of 125 or 0. If the target is 125, we subtract 125.

Algorithm

Let's calculate dp(i, target) using a top down dp. Here, i will be the exponent of the block x^ix 
i
  being considered, and target will be the remaining target, already divided by x^ix 
i
 .

From here, the recursion is straightforward: r = \text{target} \pmod xr=target(modx), and we either subtract rr blocks or add (x-r)(x−r) of them. The base cases are easily deduced - see the code for more details.


(I) As for the official solution:
Notable points are: (a) division is only performed when generating 1 since it does not make sense to write sth like: a * a / a. (b) multiplication is the only operator that should be constantly employed. (c) plus and minus are carried out when separating blocks of mulipl and divi operations.

Thus, differing from "Race car (818)", for a given integer, there is no need here to worry about how much to exceed and how much from the target shall we stop and resume. As we are trying to achieve target in shortest time possible, now there are only two options each time, e.g. for target = 16, x = 5, we only consider 15 and 20 because what else may be chosen (10/25) would require extra steps to reach 15 or 20 from which on the time to reach target would be the same as if reach directly from 15 or 20.

Back to this question, we are here sort of disclosing the series of blocks of operations sum up to target (e.g. 94 = 3^4 + 3^2 + 3 + 1 or ...). As we are given a number initially, we shall check all such possible blocks to derive the shortest one. For a given number, to derive the underlying block structure, we can constantly zero-out blocks. For instance, for the single 1 above, it must be generated based on 3/3 which decisively require two steps (/ and + by others). After removing the "1" block, dividing the rest by 3 gives 3^3 + 3 + 1. Now this new "1" can also be removed but it does not involve division. Instead, if we have recorded how many block-wise division by 3 have been done (1 by now), we would know that this "1" originates from 3. And if we block-wise divide further, when we have 3^2 + 1, the "1" signs the once existence of 3*3.

(II) Lee's code
e.g. 5, 907. The else loop only fits the first run (907-905 and 910-907). Then, neg records the total # of steps to go beyond and pos records that to reach furtherest not exceeding. Note, however large the value is, initially the two boundaries differ only by x and after 1st division, they differ only by 1 which is the initiation condition for the 1st run of if.

In that case, as can be found below, the two boundaries (ex & ur) now for 1st exceed and unreach would be identical. And thus, at this 1st if loop, the now four conditions proliferating from the original two can be restored to two, combining ex and ur respectively together. After this, the two ex's (25) and two ur's (20) can be evaluated identically as 910 and 905.

      1st exceed    1st unreach
            910          905
             22           21
   
          25  20       25  20
          ex  ur       ex  ur
In detail, at the start of the 1st if, the residue (cur in Lee's cpp code) calculated is that for "1st ur + ur" which is 1. This gives directly 5 - 1 = 4 for "1st ur + ex". Since we know the product after division for 1st exceed is "1" larger (22), the residue will also be "1" larger and "1st ex + ur" will be 1 + 1 = 2 and "1st ex + ex" will be 5 - 2 = 3. Then write 25 and 20 out and evaluate them in a similar way.


    int leastOpsExpressTarget(int x, int y) {
        int pos = 0, neg = 0, k, pos2, neg2, cur;
        for (k = 0; y > 0; ++k, y /= x) {
            cur = y % x;
            if (k > 0) {
                pos2 = min(cur * k + pos, (cur + 1) * k + neg);
                neg2 = min((x - cur) * k + pos, (x - cur - 1) * k + neg);
                pos = pos2, neg = neg2;
            } else {
                pos = cur * 2;
                neg = (x - cur) * 2;
            }
        }
        return min(pos, k + neg) - 1;
    }


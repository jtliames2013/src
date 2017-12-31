755. Reach a Number
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9].

Intuition

The crux of the problem is to put + and - signs on the numbers 1, 2, 3, ..., k so that the sum is target.

When target < 0 and we made a sum of Math.abs(target), we could switch the signs of all the numbers so that it equals target. Thus, the answer for a target of Math.abs(target) is the same, and so without loss of generality, we can consider only target > 0.

Now let's say k is the smallest number with S = 1 + 2 + ... + k >= target. If S == target, the answer is clearly k.

If S > target, we need to change some number signs. If delta = S - target is even, then we can always find a subset of {1, 2, ..., k} equal to delta / 2 and switch the signs, so the answer is k.

Otherwise, if delta is odd, we can't do it, as every sign change from positive to negative changes the sum by an even number. So let's consider a candidate answer of k+1, which changes delta by k+1. If this is odd, then delta will be even and we can have an answer of k+1. Otherwise, delta will be odd, and we will have an answer of k+2.

For concrete examples of the above four cases, consider the following:

If target = 3, then k = 2, delta = 0 and the answer is k = 2.
If target = 4, then k = 3, delta = 2, delta is even and the answer is k = 3.
If target = 7, then k = 4, delta = 3, delta is odd and adding k+1 makes delta even. The answer is k+1 = 5.
If target = 5, then k = 3, delta = 1, delta is odd and adding k+1 keeps delta odd. The answer is k+2 = 5.
Algorithm

Subtract ++k from target until it goes non-positive. Then k will be as described, and target will be delta as described. We can output the four cases above: if delta is even then the answer is k, if delta is odd then the answer is k+1 or k+2 depending on the parity of k.

class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int k=0;
        while (target>0)
            target-=++k;
        return target%2==0?k:(k+1+k%2);
    }
};


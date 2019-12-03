862. Shortest Subarray with Sum at Least K
Hard

656

17

Favorite

Share
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
 

Note:

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9


What makes this problem hard is that we have negative values. If you haven't already done the problem with positive integers only, I highly recommend solving it first, as I will use its Sliding Window solution to reach the Deque solution here. You can find the problem here , and a Sliding window solution here.

Recall of the Sliding window solution in a positive array
The Sliding window solution finds the subarray we are looking for in a linear time complexity. The idea behind it is to maintain two pointers: start and end, moving them in a smart way to avoid examining all possible values 0<=end<=n-1 and 0<=start<=end (to avoid brute force).
What it does is:

Incremeting the end pointer while the sum of current subarray (defined by current values of start and end) is smaller than the target.
Once we satisfy our condition (the sum of current subarray >= target) we keep incrementing the start pointer until we violate it (until sum(array[start:end+1]) < target).
Once we violate the condition we keep incrementing the end pointer until the condition is satisfied again and so on.
The reason why we stop incrementing start when we violate the condition is that we are sure we will not satisfy it again if we keep incrementing start. In other words, if the sum of the current subarray start -> end is smaller than the target then the sum of start+1 -> end is neccessarily smaller than the target. (positive values)
The problem with this solution is that it doesn't work if we have negative values, this is because of the sentence above Once we "violate" the condition we stop incrementing start.

Problem of the Sliding window with negative values
Now, let's take an example with negative values nums = [3, -2, 5] and target=4. Initially start=0, we keep moving the end pointer until we satisfy the condition, here we will have start=0 and end=2. Now we are going to move the start pointer start=1. The sum of the current subarray is -2+5=3 < 4 so we violate the condition. However if we just move the start pointer another time start=2 we will find 5 >= 4 and we are satisfying the condition. And this is not what the Sliding window assumes.

Deque solution
The Deque solution is just a modification of the Sliding window solution above. We will modify the way we are updating start.
Let's explain the Deque solution based on the code of @Lee215 by answering some questions :

    def shortestSubarray(self, A, K):
        N = len(A)
        B = [0] * (N + 1)
        for i in range(N): B[i + 1] = B[i] + A[i]
        d = collections.deque()
        res = N + 1
        for i in xrange(N + 1):
            while d and B[i] - B[d[0]] >= K: res = min(res, i - d.popleft())
            while d and B[i] <= B[d[-1]]: d.pop()
            d.append(i)
        return res if res <= N else -1
What does the Deque store :
The deque stores the possible values of the start pointer. Unlike the sliding window, values of the start variable will not necessarily be contiguous.

Why is it increasing :
So that when we move the start pointer and we violate the condition, we are sure we will violate it if we keep taking the other values from the Deque. In other words, if the sum of the subarray from start=first value in the deque to end is smaller than target, then the sum of the subarray from start=second value in the deque to end is necessarily smaller than target.
So because the Deque is increasing (B[d[0]] <= B[d[1]]), we have B[i] - B[d[0]] >= B[i] - B[d[1]], which means the sum of the subarray starting from d[0] is greater than the sum of the sub array starting from d[1].

Why do we have a prefix array and not just the initial array like in sliding window :
Because in the sliding window when we move start (typically when we increment it) we can just substract nums[start-1] from the current sum and we get the sum of the new subarray. Here the value of the start is jumping and one way to compute the sum of the current subarray in a constant time is to have the prefix array.

Why using Deque and not simply an array :
We can use an array, however we will find ourselves doing only three operations:
1- remove_front : when we satisfy our condition and we want to move the start pointer
2- append_back : for any index that may be a future start pointer
3- remove_back : When we are no longer satisfying the increasing order of the array
Deque enables doing these 3 operations in a constant time.


class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n=A.size(), res=INT_MAX;
        deque<int> dq;
        for (int i=0; i<n; ++i) {
            if (i>0) A[i]+=A[i-1];
            if (A[i]>=K) res=min(res, i+1);
            while (!dq.empty() && A[i]-A[dq.front()]>=K) {
                res=min(res, i-dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && A[i]<=A[dq.back()]) {
                // make dq monotonically increasing
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return res==INT_MAX?-1:res;
    }
};


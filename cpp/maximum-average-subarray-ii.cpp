644. Maximum Average Subarray II
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
Note:
1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.

class Solution {
public:
    bool isSmaller(vector<int>& nums, double mid, int k) {
        double sum=0, pre=0, minPre=0;
        int i=0;
        for (; i<k; i++) sum+=nums[i]-mid;
        if (sum>=0) return true;
        
        for (; i<nums.size(); i++) {
            sum+=nums[i]-mid;
            pre+=nums[i-k]-mid;
            minPre=min(minPre, pre);
            if (sum>=minPre) return true;
        }
        
        return false;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        double minVal=INT_MAX, maxVal=INT_MIN;
        for (auto n:nums) {
            minVal=min(minVal, (double)n);
            maxVal=max(maxVal, (double)n);
        }
        double prev=minVal, mid;
        while (1) {
            mid=(maxVal+minVal)*0.5;            
            if (abs(mid-prev)<=0.00001) break;
            
            if (isSmaller(nums, mid, k)) minVal=mid;
            else maxVal=mid;            
            prev=mid;
        }
                    
        return mid;
    }
};

Algorithm

To understand the idea behind this method, let's look at the following points. Firstly, we know that the value of the average could lie between the range (min, max)(min,max). Here, minmin and maxmax refer to the minimum and the maximum values out of the given numsnums array. This is because, the average can't be lesser than the minimum value and can't be larger than the maximum value.

But, in this case, we need to find the maximum average of a subarray with atleast kk elements. The idea in this method is to try to approximate(guess) the solution and to try to find if this solution really exists. If it exists, we can continue trying to approximate the solution even to a further precise value, but choosing a larger number as the next approximation. But, if the initial guess is wrong, and the initial maximum average value(guessed) isn't possible, we need to try with a smaller number as the next approximate.

Now, instead of doing the guesses randomly, we can make use of Binary Search. With minmin and maxmax as the initial numbers to begin with, we can find out the midmid of these two numbers given by (min+max)/2(min+max)/2. Now, we need to find if a subarray with length greater than or equal to kk is possible with an average sum greater than this midmid value.

To determine if this is possible in a single scan, let's look at an observation. Suppose, there exist jj elements, a_1, a_2, a_3..., a_ja
​1
​​ ,a
​2
​​ ,a
​3
​​ ...,a
​j
​​  in a subarray within numsnums such that their average is greater than midmid. In this case, we can say that

(
a
1
+
a
2
+
a
3
.
.
.
+
a
j
)
/
j
≥
m
i
d
(a1+a2+a3...+aj)/j≥mid or

(
a
1
+
a
2
+
a
3
.
.
.
+
a
j
)
≥
j
∗
m
i
d
(a1+a2+a3...+aj)≥j∗mid or

(
a
1
−
m
i
d
)
+
(
a
2
−
m
i
d
)
+
(
a
3
−
m
i
d
)
.
.
.
+
(
a
j
−
m
i
d
)
≥
0
(a1−mid)+(a2−mid)+(a3−mid)...+(aj−mid)≥0

Thus, we can see that if after subtracting the midmid number from the elements of a subarray with more than k-1k−1 elements, within numsnums, if the sum of elements of this reduced subarray is greater than 0, we can achieve an average value greater than midmid. Thus, in this case, we need to set the midmid as the new minimum element and continue the process. Otherwise, if this reduced sum is lesser than 0 for all subarrays with greater than or equal to kk elements, we can't achieve midmid as the average. Thus, we need to set midmid as the new maximum element and continue the process.

In order to determine if such a subarray exists in a linear manner, we keep on adding nums[i]-midnums[i]−mid to the sumsum obtained till the i^{th}i
​th
​​  element while traversing over the numsnums array. If on traversing the first kk elements, the sumsum becomes greater than or equal to 0, we can directly determine that we can increase the average beyond midmid. Otherwise, we continue making additions to sumsum for elements beyond the k^{th}k
​th
​​  element, making use of the following idea.

If we know the cumulative sum upto indices ii and jj, say sum_isum
​i
​​  and sum_jsum
​j
​​  respectively, we can determine the sum of the subarray between these indices(including jj) as sum_j - sum_isum
​j
​​ −sum
​i
​​ . In our case, we want this difference between the cumulative sums to be greater than or equal to 0 as discusssed above. Further, for sum_isum
​i
​​  as the cumulative sum upto the current(i^{th}i
​th
​​ ) index, all we need is 
s
u
m
i
−
s
u
m
j
≥
0
sumi−sumj≥0 such that 
j
−
i
≥
k
j−i≥k. To achive this, instead of checking with all possible values of sum_jsum
​j
​​ , we can just consider the minimum cumulative sum upto the index j-ij−i. This is because if the required condition can't be sastisfied with the minimum sum_jsum
​j
​​ , it can never be satisfied with a larger value.

To fulfil this, we make use of a prevprev variable which again stores the cumulative sums but, its current index(for cumulative sum) lies behind the current index for sumsum at an offset of kk units. Thus, by finding the minimum out of prevprev and the last minimum value, we can easily find out the required minimum sum value.

Every time after checking the possiblility with a new midmid value, at the end, we need to settle at some value as the average. But, we can observe that eventually, we'll reach a point, where we'll keep moving near some same value with very small changes. In order to keep our precision in control, we limit this process to 10^-510
​−
​​ 5 precision, by making use of errorerror and continuing the process till errorerror becomes lesser than 0.00001 .

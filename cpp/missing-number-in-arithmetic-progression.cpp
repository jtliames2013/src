1228. Missing Number In Arithmetic Progression
Easy

48

3

Favorite

Share
In some array arr, the values were in arithmetic progression: the values arr[i+1] - arr[i] are all equal for every 0 <= i < arr.length - 1.

Then, a value from arr was removed that was not the first or last value in the array.

Return the removed value.

 

Example 1:

Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].
Example 2:

Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].
 

Constraints:

3 <= arr.length <= 1000
0 <= arr[i] <= 10^5

Audible
|
2

1.
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size(), sum=0;
        for (auto a:arr) sum+=a;
        return (arr[0]+arr[n-1])*(n+1)/2-sum;
    }
};

2. binary search
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size(), diff=(arr[n-1]-arr[0])/n, l=0, r=n-1, mid;
        while (l<r) {
            mid=l+(r-l)/2;
            if (arr[0]+diff*mid==arr[mid]) l=mid+1;
            else r=mid;
        }
        return arr[r]-diff;
    }
};


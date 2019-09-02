1089. Duplicate Zeros
Easy

137

100

Favorite

Share
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size(), i=n-1, j=n+count(arr.begin(), arr.end(), 0)-1;        
        for (; i>=0; --i) {        
            if (j<n) arr[j]=arr[i];
            --j;
            if (arr[i]==0) {        
                if (j<n) arr[j]=0;
                --j;
            }
        }
    }
};

1213. Intersection of Three Sorted Arrays
Easy

49

3

Favorite

Share
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

 

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
 

Constraints:

1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000

Facebook
|
3

TripAdvisor
|
2

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> res;
        int i1=0, i2=0, i3=0;
        for (; i1<arr1.size() && i2<arr2.size() && i3<arr3.size(); ) {
            if (arr1[i1]==arr2[i2] && arr2[i2]==arr3[i3]) {
                res.push_back(arr1[i1]);
                i1++;
                i2++;
                i3++;
            } else if (arr1[i1]<arr2[i2]) {
                i1++;
            } else if (arr2[i2]<arr3[i3]) {
                i2++;
            } else {
                i3++;
            }
        }
        
        return res;
    }
};


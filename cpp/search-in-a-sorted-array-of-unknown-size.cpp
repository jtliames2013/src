702. Search in a Sorted Array of Unknown Size
Medium

215

18

Favorite

Share
Given an integer array sorted in ascending order, write a function to search target in nums.  If target exists, then return its index, otherwise return -1. However, the array size is unknown to you. You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.

 

Example 1:

Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: array = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in the array are unique.
The value of each element in the array will be in the range [-9999, 9999].

Amazon
|
2

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l, r=1, mid;
        while (target>reader.get(r)) r<<=1;
        l=r>>1;
        
        while (l<=r) {
            mid=l+(r-l)/2;
            if (reader.get(mid)==target) return mid;
            else if (reader.get(mid)<target) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};


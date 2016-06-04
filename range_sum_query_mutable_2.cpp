// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
using namespace std;

Approach #3 (Segment tree) [Accepted]

Algorithm

Segment tree is a very flexible data structure, because it is used to solve numerous range query problems like finding minimum, maximum, sum, greatest common divisor, least common denominator in array in logarithmic time.

Illustration of Segment tree

Figure 2. Illustration of Segment tree.

The segment tree for array a[0, 1, \ldots ,n-1]a[0,1,…,n−1] is a binary tree in which each node contains aggregate information (min, max, sum, etc.) for a subrange [i \ldots j][i…j] of the array, as its left and right child hold information for range [i \ldots \frac{i+j}{2}][i…
​2
​
​i+j
​​ ] and [\frac{i + j}{2} + 1, j][
​2
​
​i+j
​​ +1,j].

Segment tree could be implemented using either an array or a tree. For an array implementation, if the element at index ii is not a leaf, its left and right child are stored at index 2i2i and 2i + 12i+1 respectively.

In the example above (Figure 2), every leaf node contains the initial array elements {2,4,5,7,8,9}. The internal nodes contain the sum of the corresponding elements in range - (11) for the elements from index 0 to index 2. The root (35) being the sum of its children (11);(24), holds the total sum of the entire array.

Segment Tree can be broken down to the three following steps:

Pre-processing step which builds the segment tree from a given array.
Update the segment tree when an element is modified.
Calculate the Range Sum Query using the segment tree.
1. Build segment tree

We will use a very effective bottom-up approach to build segment tree. We already know from the above that if some node pp holds the sum of [i \ldots j][i…j] range, its left and right children hold the sum for range [i \ldots \frac{i + j}{2}][i…
​2
​
​i+j
​​ ] and [\frac{i + j}{2} + 1, j][
​2
​
​i+j
​​ +1,j] respectively.

Therefore to find the sum of node pp, we need to calculate the sum of its right and left child in advance.

We begin from the leaves, initialize them with input array elements a[0, 1, \ldots, n-1]a[0,1,…,n−1]. Then we move upward to the higher level to calculate the parents' sum till we get to the root of the segment tree.

Java

int[] tree;
int n;
public NumArray(int[] nums) {
    if (nums.length > 0) {
        n = nums.length;
        tree = new int[n * 2];
        buildTree(nums);
    }
}
private void buildTree(int[] nums) {
    for (int i = n, j = 0;  i < 2 * n; i++,  j++)
        tree[i] = nums[j];
    for (int i = n - 1; i > 0; --i)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
Complexity Analysis

Time complexity : O(n)O(n)

Time complexity is O(n)O(n), because we calculate the sum of one node during each iteration of the for loop. There are approximately 2n2n nodes in a segment tree.

This could be proved in the following way: Segmented tree for array with nn elements has nn leaves (the array elements itself). The number of nodes in each level is half the number in the level below.

So if we sum the number by level we will get:

n + n/2 + n/4 + n/8 + \ldots + 1 \approx 2n n+n/2+n/4+n/8+…+1≈2n

Space complexity : O(n)O(n).

We used 2n2n extra space to store the segment tree.

2. Update segment tree

When we update the array at some index ii we need to rebuild the segment tree, because there are tree nodes which contain the sum of the modified element. Again we will use a bottom-up approach. We update the leaf node that stores a[i]a[i]. From there we will follow the path up to the root updating the value of each parent as a sum of its children values.

Java

void update(int pos, int val) {
    pos += n;
    tree[pos] = val;
    while (pos > 0) {
        int left = pos;
        int right = pos;
        if (pos % 2 == 0) {
            right = pos + 1;
        } else {
            left = pos - 1;
        }
        // parent is updated after child is updated
        tree[pos / 2] = tree[left] + tree[right];
        pos /= 2;
    }
}
Complexity Analysis

Time complexity : O(\log n)O(logn).

Algorithm has O(\log n)O(logn) time complexity, because there are a few tree nodes with range that include iith array element, one on each level. There are \log(n)log(n) levels.

Space complexity : O(1)O(1).

3. Range Sum Query

We can find range sum query [L, R][L,R] using segment tree in the following way:

Algorithm hold loop invariant:

l \le rl≤r and sum of [L \ldots l][L…l] and [r \ldots R][r…R] has been calculated, where ll and rr are the left and right boundary of calculated sum. Initially we set ll with left leaf LL and rr with right leaf RR. Range [l, r][l,r] shrinks on each iteration till range borders meets after approximately \log nlogn iterations of the algorithm

Loop till l \le rl≤r
Check if ll is right child of its parent PP
ll is right child of PP. Then PP contains sum of range of ll and another child which is outside the range [l, r][l,r] and we don't need parent PP sum. Add ll to sumsum without its parent PP and set ll to point to the right of PP on the upper level.
ll is not right child of PP. Then parent PP contains sum of range which lies in [l, r][l,r]. Add PP to sumsum and set ll to point to the parent of PP
Check if rr is left child of its parent PP
rr is left child of PP. Then PP contains sum of range of rr and another child which is outside the range [l, r][l,r] and we don't need parent PP sum. Add rr to sumsum without its parent PP and set rr to point to the left of PP on the upper level.
rr is not left child of PP. Then parent PP contains sum of range which lies in [l, r][l,r]. Add PP to sumsum and set rr to point to the parent of PP
Java

public int sumRange(int l, int r) {
    // get leaf with value 'l'
    l += n;
    // get leaf with value 'r'
    r += n;
    int sum = 0;
    while (l <= r) {
        if ((l % 2) == 1) {
           sum += tree[l];
           l++;
        }
        if ((r % 2) == 0) {
           sum += tree[r];
           r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}
Complexity Analysis

Time complexity : O(\log n)O(logn)

Time complexity is O(\log n)O(logn) because on each iteration of the algorithm we move one level up, either to the parent of the current node or to the next sibling of parent to the left or right direction till the two boundaries meet. In the worst-case scenario this happens at the root after \log nlogn iterations of the algorithm.

Space complexity : O(1)O(1).

class NumArray {
public:
    NumArray(vector<int> &nums) {
        n=nums.size();
        if (n>0) {
            segtree.resize(2*n);
        }

        // Build segment tree
        for (int i=n, j=0; i<2*n; i++, j++) {
            segtree[i]=nums[j];
        }

        for (int i=n-1; i>0; i--) {
            segtree[i]=segtree[2*i]+segtree[2*i+1];
        }
    }

    void update(int i, int val) {
        i+=n;
        segtree[i]=val;

        while (i>0) {
            int left=i;
            int right=i;
            if (i%2==0) {
                right=i+1;
            } else {
                left=i-1;
            }

            segtree[i/2]=segtree[left]+segtree[right];
            i=i/2;
        }
    }

    int sumRange(int i, int j) {
        i+=n;
        j+=n;

        int sum=0;
        while (i<=j) {
            if ((i%2)==1) {
                sum+=segtree[i];
                i++;
            }

            if ((j%2)==0) {
                sum+=segtree[j];
                j--;
            }

            i/=2;
            j/=2;
        }

        return sum;
    }
private:
    vector<int> segtree;
    int n;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
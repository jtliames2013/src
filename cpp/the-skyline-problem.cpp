218. The Skyline Problem
DescriptionHintsSubmissionsSolutions
Total Accepted: 40221
Total Submissions: 150700
Difficulty: Hard
Contributor: LeetCode
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
Credits:
Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.

Subscribe to see which companies asked this question.

Hide Tags Binary Indexed Tree Segment Tree Heap Divide and Conquer

https://www.youtube.com/watch?v=GSBLe8cKu0s
http://www.cnblogs.com/easonliu/p/4531020.html
分别将每个线段的左边节点与右边节点存到新的vector height中，根据x坐标值排序，然后遍历求拐点。求拐点的时候用一个最大化heap来保存
当前的楼顶高度，遇到左边节点，就在heap中插入高度信息，遇到右边节点就从heap中删除高度。分别用pre与cur来表示之前的高度与当前的
高度，当cur != pre的时候说明出现了拐点。在从heap中删除元素时要注意，我使用priority_queue来实现，priority_queue并不提供删除的
操作，所以又用了别外一个unordered_map来标记要删除的元素。在从heap中pop的时候先看有没有被标记过，如果标记过，就一直pop直到空或
都找到没被标记过的值。别外在排序的时候要注意，如果两个节点的x坐标相同，我们就要考虑节点的其它属性来排序以避免出现冗余的答案。
且体的规则就是如果都是左节点，就按y坐标从大到小排，如果都是右节点，按y坐标从小到大排，一个左节点一个右节点，就让左节点在前。
下面是AC的代码。

使用一些技巧可以大大减少编码的复杂度，priority_queue并没有提供erase操作，但是multiset提供了，而且multiset内的数据是按BST排好序
的。在区分左右节点时，我之前自己建了一个结构体，用一个属性type来标记。这里可以用一个小技巧，那就是把左边节点的高度值设成负数，
右边节点的高度值是正数，这样我们就不用额外的属性，直接用pair<int, int>就可以保存了。而且对其排序，发现pair默认的排序规则就已经
满足要求了。

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res, lines;
        for (auto& b:buildings) {
            lines.push_back({b[0], -b[2]}); // start of building
            lines.push_back({b[1], b[2]}); // end of building
        }
        sort(lines.begin(), lines.end());
        multiset<int> height;
        // insert the base line, to be used when no line
        height.insert(0);
        int mx=0, curr=0;

        for (auto& l:lines) {
            if (l[1]<0) height.insert(-l[1]);
            else height.erase(height.find(l[1]));

            curr=*(height.rbegin());
            if (curr!=mx) {
                res.push_back({l[0], curr});
                mx=curr;
            }
        }
        return res;
    }
};

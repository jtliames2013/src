335. Self Crossing
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2],
┌───┐
│   │
└───┼──>
    │

Return true (self crossing)

Example 2:
Given x = [1, 2, 3, 4],
┌──────┐
│      │
│
│
└────────────>

Return false (not self crossing)
Example 3:
Given x = [1, 1, 1, 1],
┌───┐
│   │
└───┼>

Return true (self crossing)
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Hide Tags Math


不交叉的有以下三种情况
平行移动的距离是不断的增加的（螺旋形上升）
平行移动的距离是不断的减少的（螺旋形下降）
平行移动的距离先增加后减少，并且再也不增加。

            b                              b
   +----------------+             +----------------+
   |                |             |                |
   |                |             |                | a
 c |                |           c |                |
   |                | a           |                |    f
   +----------->    |             |                | <----+
            d       |             |                |      | e
                    |             |                       |
                                  +-----------------------+
                                               d

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n=x.size();
        if (n<4) return false;
        
        int t0=0, t1=0, t2=x[0], t3=x[1], t4=x[2], t5;
        bool increase=t4>t2;
        for (int i=3; i<n; i++) {
            t5=x[i];
            if (increase) {
                if (t5<=t3) increase=false;
            } else {
                if ((t3>t1 && t4+t0>=t2 && t5+t1>=t3) || // increase first and decrease
                    (t5>=t3)) { // decrease
                        return true;
                    }
            }
            t0=t1;
            t1=t2;
            t2=t3;
            t3=t4;
            t4=t5;
        }
        
        return false;
    }
};


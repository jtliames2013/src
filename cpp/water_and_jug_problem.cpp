365. Water and Jug Problem 
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False
Credits:
Special thanks to @vinod23 for adding this problem and creating all test cases.

Hide Company Tags Microsoft
Hide Tags Math

题目可以表示为如下等式:

mx + ny = z
若m,n>0说明往里面加水，若m,n <0则说明清空
如x=3，y=5 可以有  3 x  + (-1)y = 4 即 m=3 , n=-1 ，也就是说我们需要往3这个杯子装满3次，5这个杯子倒掉1次

首先往3的杯子注满水，然后倒入倒入5    杯子情况为： 0，3
接着把3的杯子注满水，在倒入5 ，杯子情况为  1，5
接着把5的杯子倒掉， 把3的杯子装入5， 这样为 0，1
接着把3的杯子注满水，倒入5， 这样0，4
可以参考  ： http://www.math.tamu.edu/~dallen/hollywood/diehard/diehard.htm

本题中，若mx + ny = z 有解，则一定有z为GCD(x,y) 的整数倍，否则无解。

且需要满足条件 x + y >=z

class Solution {
public:
    int gcd(int a,int b){
        return b==0? a: gcd(b,a%b);
    }

    bool canMeasureWater(int x, int y, int z) {
        return (x + y == z) || ((x + y > z ) && z % gcd(x,y) == 0);
    }
};


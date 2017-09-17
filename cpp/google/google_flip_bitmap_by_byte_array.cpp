flip bitmap represented by byte array

把一个bit image存在byte array里，比如：
0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0
0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0
就是
0x01 0x02 0x04 0x08

要求左右翻转，得到
1 0 0 0 0 0 0 0. from: 1point3acres.com/bbs 
0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0

函数签名：void flip(int8 *image, int width, int height) 鏉ユ簮涓€浜�.涓夊垎鍦拌鍧�. 

做法是row by row，每个row，用2个pointer相遇，先flip byte，然后swap。每个byte，写个函数做flip。
. From 1point 3acres bbs
复杂度是O(N)，不能更好了。

follow up： 怎么parallel优化，这里每个row可以独立处理，每个pair of byte可是独立，这两个比较naive。但是byte flip就不懂了，最后讨论了一下写了些公式，但我还是没看出怎么能比原来做的好。


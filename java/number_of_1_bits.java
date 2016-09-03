public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        int i=0;
        while (i<32) {
            count+=n & 0x1;
            n>>=1;
            i++;
        }
        return count;
    }
}

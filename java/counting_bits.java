public class Solution {
    public int[] countBits(int num) {
        int[] res=new int[num+1];
        res[0]=0;
        if (num>0) res[1]=1;
        for (int i=2; i<=num; i++) {
            int last=i & 0x1;
            res[i]=res[i>>1]+last;
        }
        
        return res;
    }
}

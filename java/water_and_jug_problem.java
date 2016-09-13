public class Solution {
    int gcd(int a,int b){
        return b==0? a: gcd(b,a%b);
    }

    public boolean canMeasureWater(int x, int y, int z) {
        return (x + y == z) || ((x + y > z ) && z % gcd(x,y) == 0);        
    }
}

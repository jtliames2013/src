public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res=new ArrayList<Integer>();
        if (n==0) {
            res.add(0);
            return res;
        }
        if (n==1) {
            res.add(0);
            res.add(1);
            return res;
        }
        
        List<Integer> left=grayCode(n-1);
        List<Integer> right=grayCode(n-1);
        for (int i=right.size()-1; i>=0; i--) {
            int num=right.get(i);
            num|=(1<<(n-1));
            left.add(num);
        }
        
        return left;
    }
}

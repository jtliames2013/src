public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        int n=nums.length;
        if (n==0) return res;
        getPerm(res, nums, 0);
        return res;
    }
    private void swap(int[] num, int i, int j) {
        int tmp=num[i];
        num[i]=num[j];
        num[j]=tmp;
    }
    private void getPerm(List<List<Integer>> res, int[] num, int start) {
        if (start==num.length) {
            List<Integer> l=new ArrayList<>();
            for (int i=0; i<num.length; i++) l.add(num[i]);
            res.add(l);
            return;
        }
        for (int i=start; i<num.length; i++) {
            swap(num, start, i);
            getPerm(res, num, start+1);
            swap(num, start, i);
        }
    }
}

public class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length==0) return 0;
        int localminProd=nums[0], localmaxProd=nums[0];
        int maxProd=nums[0];
        
        for (int i=1; i<nums.length; i++) {
            int tmp=localmaxProd;
            localmaxProd=Math.max(Math.max(localmaxProd*nums[i], localminProd*nums[i]),nums[i]);
            localminProd=Math.min(Math.min(tmp*nums[i], localminProd*nums[i]),nums[i]);
            maxProd=Math.max(maxProd, localmaxProd);
        }
        
        return maxProd;
    }
}

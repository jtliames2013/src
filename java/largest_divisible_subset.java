public class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        LinkedList<Integer> res=new LinkedList<Integer>();                
        if (nums==null || nums.length==0) return res;
        Arrays.sort(nums);
        
        int[] dp=new int[nums.length];        
        int[] parent=new int[nums.length];
        Arrays.fill(parent, -1);
        int maxNum=0, maxIdx=-1;
        
        for (int i=0; i<nums.length; i++) {
            dp[i]=1;
            for (int j=0; j<i; j++) {
                if (nums[i]%nums[j]==0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                }                
            }
            
            if (maxNum<dp[i]) {
                maxNum=dp[i];
                maxIdx=i;
            }
        }
        
        for (int i=maxIdx; i!=-1; ) {
            res.addFirst(nums[i]);
            i=parent[i];
        }
        
        return res;
    }
}

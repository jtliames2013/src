public class Solution {
    Map<Integer,Integer> count=new HashMap<Integer,Integer>();
    public int combinationSum4(int[] nums, int target) {
        int res=0;
        if (nums==null||nums.length==0||target<0) return 0;
        if (target==0) return 1;
        if (count.containsKey(target)) return count.get(target);
        
        for (int i:nums) {
            res+=combinationSum4(nums, target-i);
        }
        
        count.put(target, res);
        return res;
    }
}

2.
public class Solution {
    public int combinationSum4(int[] nums, int target) {
        if (nums==null||nums.length==0||target<0) return 0;
        Arrays.sort(nums);
        int[] dp=new int[target+1];
        dp[0]=1;
        for (int i=1; i<=target; i++) {
            for (int n:nums) {
                if (i<n) break;
                dp[i]+=dp[i-n];
            }
        }
        
        return dp[target];
    }
}

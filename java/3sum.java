public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        int n=nums.length;
        if (n==0)  return res;
        Arrays.sort(nums);
        for (int i=0; i<n-2; i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
                int l=i+1, r=n-1;
                while (l<r) {
                    if (nums[l]+nums[r]==-nums[i]) {
                        if ((l==i+1 || nums[l]!=nums[l-1]) && (r==n-1 || nums[r]!=nums[r+1])) {
                            res.add(new ArrayList(Arrays.asList(nums[i], nums[l], nums[r])));
                        }
                        l++;
                        r--;
                    } else if (nums[l]+nums[r]<-nums[i]) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        
        return res;
    }
}

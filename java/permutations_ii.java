public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        Arrays.sort(nums);
        getPerm(res, new ArrayList<>(), nums, new boolean[nums.length]);
        return res;
    }
    private void getPerm(List<List<Integer>> res, List<Integer> output, int[] nums, boolean[] selected) {
        if (output.size()==nums.length) {
            res.add(new ArrayList<>(output));
            return;
        }
        for (int i=0; i<nums.length; i++) {
            if (selected[i]==false && (i==0 || selected[i-1]==true || nums[i]!=nums[i-1])) {
                selected[i]=true;
                output.add(nums[i]);
                getPerm(res, output, nums, selected);
                output.remove(output.size()-1);
                selected[i]=false;
            }
        }
    }
}

public class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res=new ArrayList<Integer>();
        int n1=0, n2=0, c1=0, c2=0;
        for (int i=0; i<nums.length; i++) {
            if (c1==0 && c2==0) {
                n1=nums[i];
                c1++;
            } else if (c1==0) {
                if (n2==nums[i]) c2++;
                else {
                    n1=nums[i];
                    c1++;
                }
            } else if (c2==0) {
                if (n1==nums[i]) c1++;
                else {
                    n2=nums[i];
                    c2++;
                }    
            } else {
                if (n1==nums[i]) c1++;
                else if (n2==nums[i]) c2++;
                else {
                    c1--;
                    c2--;
                }
            }
        }
        
        c1=c2=0;
        for (int i=0; i<nums.length; i++) {
            if (nums[i]==n1) c1++;
            else if (nums[i]==n2) c2++;
        }
        
        if (c1>nums.length/3) res.add(n1);
        if (c2>nums.length/3) res.add(n2);
        
        return res;
    }
}

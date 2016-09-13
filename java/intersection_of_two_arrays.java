public class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> inter=new ArrayList<Integer>();
        int n1=nums1.length;
        int n2=nums2.length;
        if (n1==0||n2==0) return new int[0];
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        for (int i=0, j=0; i<n1 && j<n2; ) {
            if (nums1[i]<nums2[j]) {
                i++;
            } else if (nums1[i]>nums2[j]) {
                j++;
            } else {
                int num=nums1[i];
                inter.add(num);
                while (i<n1 && nums1[i]==num) i++;
                while (j<n2 && nums2[j]==num) j++;
            }
        }
        
        int[] res=new int[inter.size()];
        for (int i=0; i<inter.size(); i++) res[i]=inter.get(i);
        return res;
    }
}

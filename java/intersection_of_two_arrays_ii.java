public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> res=new ArrayList<Integer>();
        Map<Integer, Integer> map1=new HashMap<Integer, Integer>();
        Map<Integer, Integer> map2=new HashMap<Integer, Integer>();
        
        for (int i:nums1) {
            map1.put(i, map1.getOrDefault(i,0)+1);
        }
        
        for (int i:nums2) {
            map2.put(i, map2.getOrDefault(i,0)+1);
        }

        for (Map.Entry<Integer,Integer> entry:map2.entrySet()) {
            if (map1.containsKey(entry.getKey())) {
                int count=Math.min(entry.getValue(), map1.get(entry.getKey()));
                for (int i=0; i<count; i++) res.add(entry.getKey());
            }
        }
        
        int[] result=new int[res.size()];
        for (int i=0; i<res.size(); i++) result[i]=res.get(i);
        return result;
    }
}

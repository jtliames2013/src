public class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> res=new ArrayList<Integer>();
        Map<Integer,Integer> count=new HashMap<Integer,Integer>();
        for (int n:nums) {
            count.put(n, count.getOrDefault(n, 0)+1);
        }
        
        PriorityQueue<Map.Entry<Integer,Integer>> pq=new PriorityQueue<Map.Entry<Integer,Integer>>(new Comparator<Map.Entry<Integer, Integer>>(){
                    @Override
                    public int compare(Map.Entry<Integer, Integer> a, Map.Entry<Integer, Integer> b) {
                        return b.getValue()-a.getValue();
                    }
                });
                
        for (Map.Entry<Integer, Integer> entry:count.entrySet()) {
            pq.offer(entry);
        }
        
        for (int i=0; i<k; i++) {
            Map.Entry<Integer, Integer> entry=pq.poll();
            if (entry!=null) {
                res.add(entry.getKey());
            }
        }
        
        return res;
    }
}

public class Solution {
    boolean isPalin(String s) {
        int l=0, r=s.length()-1;
        while (l<r) {
            if (s.charAt(l)!=s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }
    
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        Map<String,Integer> pos=new HashMap<>();
        for (int i=0; i<words.length; i++) {
            pos.put(words[i], i);
        }
        
        for (int i=0; i<words.length; i++) {
            if (words[i].isEmpty()) continue;
            
            for (int j=0; j<words[i].length(); j++) {
                String left=words[i].substring(0, j);
                String right=words[i].substring(j);
                if (isPalin(left)) {
                    StringBuilder sb=new StringBuilder(right);
                    sb.reverse();
                    if (pos.containsKey(sb.toString())) {
                        if (pos.get(sb.toString())!=i) {
                            res.add(Arrays.asList(pos.get(sb.toString()),i));
                        }
                    }
                }
                
                if (isPalin(right)) {
                    StringBuilder sb=new StringBuilder(left);
                    sb.reverse();
                    if (pos.containsKey(sb.toString())) {
                        res.add(Arrays.asList(i, pos.get(sb.toString())));
                        if (left.isEmpty()) {
                            res.add(Arrays.asList(pos.get(sb.toString()),i));
                        }
                    }
                }
            }
        }
        
        return res;
    }
}

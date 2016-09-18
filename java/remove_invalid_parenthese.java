public class Solution {
    boolean isValid(char[] s) {
        int count=0;
        for (int i=0; i<s.length; i++) {
            if (s[i]=='(') count++;
            else if (s[i]==')') {
                count--;
                if (count<0) return false;
            }
        }    
        return count==0;
    }
    
    public List<String> removeInvalidParentheses(String s) {
        List<String> res=new ArrayList<>();
        ArrayDeque<String> queue=new ArrayDeque<>();
        HashSet<String> set=new HashSet<>();
        queue.offer(s);
        set.add(s);
        boolean found=false;
        int currLevel=1;
        int nextLevel=0;
        
        while (!queue.isEmpty()) {
            String f=queue.poll();
            if (isValid(f.toCharArray())) {
                res.add(f);
                found=true;
            }    
            currLevel--;
            
            if (!found) {
                for (int i=0; i<f.length(); i++) {
                    if (f.charAt(i)=='(' || f.charAt(i)==')') {
                        String str=f.substring(0, i)+f.substring(i+1);
                        if (!set.contains(str)) {
                            queue.offer(str);
                            set.add(str);
                        }
                    }
                }
            }
            
            if (currLevel==0) {
                currLevel=nextLevel;
                nextLevel=0;
                if (found) queue.clear();
            }
        }
        
        return res;
    }
}

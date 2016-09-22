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

2. DFS
public class Solution {
    void dfs(List<String> res, char[] s, int start, StringBuilder path, int open, int close, int count) {
        if (count<0) return;
        if (start==s.length) {
            if (open==0&&close==0) {
                res.add(path.toString());
            }
            return;
        }
        
        if (s[start]!='(' && s[start]!=')') {
            path.append(s[start]);
            dfs(res, s, start+1, path, open, close, count);
            path.deleteCharAt(path.length()-1);
        } else if (s[start]=='(') {
            int i=1;
            while (start+i<s.length && s[start+i]=='(') i++;
            path.append(s, start, i);
            dfs(res, s, start+i, path, open, close, count+i);
            path.delete(path.length()-i, path.length());
            
            if (open>0) {
                dfs(res, s, start+1, path, open-1, close, count);
            }
        } else {
            int i=1;
            while (start+i<s.length && s[start+i]==')') i++;
            path.append(s, start, i);
            dfs(res, s, start+i, path, open, close, count-i);
            path.delete(path.length()-i, path.length());
            
            if (close>0) {
                dfs(res, s, start+1, path, open, close-1, count);
            }
        }
    }
    
    public List<String> removeInvalidParentheses(String s) {
        List<String> res=new ArrayList<>();
        StringBuilder path=new StringBuilder();
        int count=0, open=0, close=0;
        for (char c:s.toCharArray()) {
            if (c=='(') count++;
            else if (c==')') {
                if (count==0) close++;
                else count--;
            }
        }
        open=count;
        if (open==0&&close==0) return Arrays.asList(s);
        
        dfs(res, s.toCharArray(), 0, path, open, close, 0);
        
        return res;
    }
}

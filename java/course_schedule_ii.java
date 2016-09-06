public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        if (numCourses==0) return new int[0];
        List<Integer> courses=new ArrayList<Integer>();
        HashSet<Integer>[] graph=new HashSet[numCourses];
        for (int i=0; i<numCourses; i++) {
            graph[i]=new HashSet<Integer>();
        }
        int[] incomingCnt=new int[numCourses];
        
        for (int i=0; i<prerequisites.length; i++) {
            if (!graph[prerequisites[i][1]].contains(prerequisites[i][0])) {
                graph[prerequisites[i][1]].add(prerequisites[i][0]);
                incomingCnt[prerequisites[i][0]]++;
            }
        }
        
        TreeSet<Integer> set=new TreeSet<Integer>();
        for (int i=0; i<incomingCnt.length; i++) {
            if (incomingCnt[i]==0) set.add(i);
        }
        
        while (!set.isEmpty()) {
            int n=set.pollFirst();
            courses.add(n);
            
            for (int neighbor:graph[n]) {
                incomingCnt[neighbor]--;
                if (incomingCnt[neighbor]==0) {
                    set.add(neighbor);
                }
            }
            graph[n].clear();            
        }
        
        for (int i=0; i<graph.length; i++) {
            if (!graph[i].isEmpty()) return new int[0];
        }
        
        int[] res=new int[courses.size()];
        for (int i=0; i<courses.size(); i++) {
            res[i]=courses.get(i);
        }
        return res;
    }
}

public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (numCourses==0) return true;
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
            
            for (int neighbor:graph[n]) {
                incomingCnt[neighbor]--;
                if (incomingCnt[neighbor]==0) {
                    set.add(neighbor);
                }
            }
            graph[n].clear();
        }
        
        for (int i=0; i<numCourses; i++) {
            if (!graph[i].isEmpty()) return false;
        }
        return true;
    }
}

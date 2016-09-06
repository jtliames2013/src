public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res=new ArrayList<Integer>();
        List<Integer> leaf=new ArrayList<Integer>();
        if (n==0) return res;
        if (n==1) {
            res.add(0);
            return res;
        } 
        if (n==2) {
            res.add(0);
            res.add(1);
            return res;
        }
        
        HashSet<Integer>[] graph=new HashSet[n];
        for (int i=0; i<n; i++) {
            graph[i]=new HashSet<Integer>();
        }
        
        for (int i=0; i<edges.length; i++) {
            graph[edges[i][0]].add(edges[i][1]);
            graph[edges[i][1]].add(edges[i][0]);
        }
        
        while (true) {
            res.clear();            
            leaf.clear();
            for (int i=0; i<n; i++) {
                // non-leaf node
                if (graph[i].size()>1) {
                    res.add(i);
                } else if (graph[i].size()==1) {
                    leaf.add(i);
                }
            }

            if (res.size()<=2) return res;
            
            for (int i=0; i<leaf.size(); i++) {
                // leaf node
                for (int neighbor:graph[leaf.get(i)]) {
                    graph[neighbor].remove(leaf.get(i));
                }
                graph[leaf.get(i)].clear();
            }
        }        
    }
}

public class Solution {
    void dfs(Map<String, PriorityQueue<String>> graph, List<String> res, String start) {
        PriorityQueue<String> cities=graph.get(start);
        while (cities!=null && !cities.isEmpty()) {
            String dest=cities.poll();
            dfs(graph, res, dest);
        }
        res.add(start);
    }
    
    public List<String> findItinerary(String[][] tickets) {
        List<String> res=new ArrayList<String>();
        Map<String, PriorityQueue<String>> graph=new HashMap<String, PriorityQueue<String>>();
        for (String[] ticket:tickets) {
            if (!graph.containsKey(ticket[0])) {
                graph.put(ticket[0], new PriorityQueue<String>());
            }
            graph.get(ticket[0]).offer(ticket[1]);
        }
        
        dfs(graph, res, "JFK");
        Collections.reverse(res);
        
        return res;
    }    
}

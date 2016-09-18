/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node==null) return null;
        Map<UndirectedGraphNode,UndirectedGraphNode> map=new HashMap<>();
        ArrayDeque<UndirectedGraphNode> queue=new ArrayDeque<>();
        Set<UndirectedGraphNode> set=new HashSet<>();
        queue.offer(node);
        UndirectedGraphNode newNode=new UndirectedGraphNode(node.label);
        map.put(node, newNode);
        set.add(node);
        
        while(!queue.isEmpty()) {
            UndirectedGraphNode f=queue.poll();
            UndirectedGraphNode parent=map.get(f);
            
            for (UndirectedGraphNode neighbor:f.neighbors) {
                if (!set.contains(neighbor)) {
                    queue.offer(neighbor);
                    set.add(neighbor);
                    UndirectedGraphNode newNeighbor=new UndirectedGraphNode(neighbor.label);
                    map.put(neighbor, newNeighbor);
                } 
                
                parent.neighbors.add(map.get(neighbor));
            }
        }
        
        return newNode;
    }
}

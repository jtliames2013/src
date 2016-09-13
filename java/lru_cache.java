public class LRUCache {
    private Map<Integer, Integer> map;
    
    public LRUCache(int capacity) {
        map = new LinkedCappedHashMap<>(capacity);
    }
    
    public int get(int key) {
        if(!map.containsKey(key)) { return -1; }
        return map.get(key);
    }
    
    public void set(int key, int value) {
        map.put(key,value);
    }

    private static class LinkedCappedHashMap<K,V> extends LinkedHashMap<K,V> {        
        int capacity;       
        LinkedCappedHashMap(int capacity) {
            super(16, 0.75f, true);
            this.capacity = capacity;
        }
        
        protected boolean removeEldestEntry(Map.Entry eldest) {
            return size() > capacity;
        }
    }
}


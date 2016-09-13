public class RandomizedCollection {

    Map<Integer,TreeSet<Integer>> map;
    List<Integer> list;
    Random rand;
    /** Initialize your data structure here. */
    public RandomizedCollection() {
        map=new HashMap<>();
        list=new ArrayList<>();
        rand=new Random();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        boolean contain=map.containsKey(val);
        if (!contain) {
            map.put(val, new TreeSet<>());
        }
        list.add(val);
        map.get(val).add(list.size()-1);
        return !contain;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val)||map.get(val).isEmpty()) return false;
        int index=list.size()-1;
        int last=list.remove(index);
        map.get(last).remove(index);
        if (last!=val) {
            int rmIdx=map.get(val).pollFirst();
            list.set(rmIdx, last);
            map.get(last).add(rmIdx);
        } 
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        return list.get(rand.nextInt(list.size()));
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

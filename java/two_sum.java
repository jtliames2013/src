import java.util.Arrays;
import java.util.Comparator;

public class HelloWorld {
	class Pair {
		int val;
		int index;
	}
	public int[] twoSum(int[] nums, int target) {              
       Pair[] pairs=new Pair[nums.length];
	   for (int i=0; i<nums.length; i++) {
		   pairs[i]=new Pair();
    	   pairs[i].val=nums[i];
    	   pairs[i].index=i;
       }
	   
	   Arrays.sort(pairs, new Comparator<Pair>(){
		   public int compare(Pair p1, Pair p2) {
			   return p1.val-p2.val;
		   }
	   });
	   
       int l=0, r=nums.length-1;
       while (l<r) {
    	   if (pairs[l].val+pairs[r].val==target) return new int [] {pairs[l].index, pairs[r].index};
    	   else if (pairs[l].val+pairs[r].val<target) l++;
    	   else r--;
       }
       
       return new int [] {0, 0};
    }
	
	public static void main(String[] args) {
		int [] nums={3,2,4};
		HelloWorld h = new HelloWorld();
		int [] res = h.twoSum(nums, 6);
		System.out.println(Arrays.toString(res));
	}
}

2. HashMap
public class Solution {
	public int[] twoSum(int[] nums, int target) {              
        Map<Integer, Integer> map=new HashMap<>();
        int[] res={0,0};
        for (int i=0; i<nums.length; i++) {
            map.put(nums[i], i);
        }
        
        for (int i=0; i<nums.length; i++) {
            if (map.containsKey(target-nums[i]) && map.get(target-nums[i])!=i) {
                res[0]=i;
                res[1]=map.get(target-nums[i]);
                break;
            }
        }
        
        return res;
    }
}


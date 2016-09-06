public class Solution {
    int partition(List<Integer> numbers, int l, int r, int pivotIndex) {
        int pivotValue=numbers.get(pivotIndex);
        Collections.swap(numbers, pivotIndex, r);
        
        int index=l;
        for (int i=l; i<r; i++) {
            if (numbers.get(i)>pivotValue) {
                if (index!=i) {
                    Collections.swap(numbers, i, index);
                }
                index++;
            }
        }
        Collections.swap(numbers, index, r);
        return index;
    }
    
    public int findKthLargest(int[] nums, int k) {
        List<Integer> numbers=new ArrayList<Integer>();
        for (int i:nums) numbers.add(i);
        
        int n=numbers.size();
        if (n==0) return 0;
        int l=0, r=n-1;
        while (true) {
            if (l==r) return numbers.get(l);
            int pivotIndex=(int)Math.random()%(r-l+1)+l;
            pivotIndex=partition(numbers, l, r, pivotIndex);
            if (pivotIndex==k-1) return numbers.get(k-1);
            else if (pivotIndex<k-1) l=pivotIndex+1;
            else r=pivotIndex-1;
        }
    }
}

2.
public class Solution {
    void swap(int[] nums, int l, int r) {
        int tmp=nums[l];
        nums[l]=nums[r];
        nums[r]=tmp;
    }
    
    int partition(int[] nums, int l, int r, int pivotIndex) {
        int pivotValue=nums[pivotIndex];
        swap(nums, pivotIndex, r);
        
        int index=l;
        for (int i=l; i<r; i++) {
            if (nums[i]>pivotValue) {
                if (index!=i) {
                    swap(nums, i, index);
                }
                index++;
            }
        }
        swap(nums, index, r);
        return index;
    }
    
    public int findKthLargest(int[] nums, int k) {
        int n=nums.length;
        if (n==0) return 0;
        int l=0, r=n-1;
        while (true) {
            if (l==r) return nums[l];
            int pivotIndex=(int)Math.random()%(r-l+1)+l;
            pivotIndex=partition(nums, l, r, pivotIndex);
            if (pivotIndex==k-1) return nums[k-1];
            else if (pivotIndex<k-1) l=pivotIndex+1;
            else r=pivotIndex-1;
        }
    }
}


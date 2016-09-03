import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class HelloWorld {    
    public int[] twoSum(int[] numbers, int target) {
        int[] res=new int[] {0, 0};
        int l=0, r=numbers.length-1;
        while (l<r) {
            if (numbers[l]+numbers[r]==target) {
                res[0]=l+1;
                res[1]=r+1;
                return res;
            } else if (numbers[l]+numbers[r]>target) {
                r--;
            } else {
                l++;
            }
        }
        
        return res;
    }
    
    public static void main(String[] args) {
    }
}


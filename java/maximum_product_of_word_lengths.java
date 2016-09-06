import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;
import java.util.PriorityQueue;
import java.lang.Math;

public class HelloWorld {    
    public int maxProduct(String[] words) {
        int n=words.length;
        int[] nums=new int[n];
        for (int i=0; i<n; i++) {
            for (int j=0; j<words[i].length(); j++) {
                nums[i] |= (1<< words[i].charAt(j)-'a'+1);
            }
        }
        
        int maxLen=0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if ((nums[i] & nums[j])==0) {
                    maxLen=Math.max(maxLen, words[i].length()*words[j].length());
                }
            }
        }
        
        return maxLen;
    }
    
    public static void main(String[] args) {
    }
}


1247. Minimum Swaps to Make Strings Equal
Medium

77

82

Favorite

Share
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

 

Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2: 

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
Example 3:

Input: s1 = "xx", s2 = "xy"
Output: -1
Example 4:

Input: s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
Output: 4
 

Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.

Example:
Input:
s1 = "xxyyxyxyxx",
s2 = "xyyxyxxxyx"

Skip equals chars, then:
s1 = "xyxyyx",
s2 = "yxyxxy"

x1 = 3, y1 = 3
x2 = 3, y2 = 3

There are 6 'x' and 6 'y', so it's valid to do swaps.

check 'x' pairs in s1
s1 = "xyxyyx",
s2 = "yxyxxy"

do 1 swap
s1 = "yyxyyx",
s2 = "yxxxxy"

ignore the equal chars
s1 = "yyyx"
s2 = "xxxy"

check 'y' pairs in s1
s1 = "yyyx"
s2 = "xxxy"

do 1 swap
s1 = "yxyx"
s2 = "yxxy"

ignore the equal chars
s1 = "yx"
s2 = "xy"

do 2 swaps
s1 = "xy"
s2 = "xy"

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1=0, y1=0, x2=0, y2=0;
        for (int i=0; i<s1.size(); ++i) {
            if (s1[i]==s2[i]) continue;
            if (s1[i]=='x') x1++;
            else y1++;
            if (s2[i]=='x') x2++;
            else y2++;
        }
        
        if ((x1+x2)%2!=0 || (y1+y2)%2!=0) return -1;
        
        // xx or yy --> one swap
        // xy or yx --> two swap
        return x1/2+y1/2+(x1%2)*2;
    }    
};


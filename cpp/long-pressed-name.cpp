925. Long Pressed Name
Easy

143

13

Favorite

Share
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0, m=name.size(), n=typed.size();
        for (; i<m && j<n; ) {
            if (name[i]!=typed[j]) return false;
            int i2=i+1, j2=j+1;
            while (i2<m && name[i2]==name[i]) i2++;
            while (j2<n && typed[j2]==typed[j]) j2++;
            if (i2-i>j2-j) return false;
            i=i2;
            j=j2;
        }
        
        return i==m && j==n;
    }
};


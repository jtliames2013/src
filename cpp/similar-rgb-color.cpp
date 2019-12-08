800. Similar RGB Color
Easy

47

310

Favorite

Share
In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:  
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Note:

color is a string of length 7.
color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
Any answer which has the same (highest) similarity as the best answer will be accepted.
All inputs and outputs should use lowercase letters, and the output is 7 characters.

Google
|
3

class Solution {
public:
    string similarRGB(string color) {
        string res="#";
        for (int i=1; i<color.size(); i+=2) {
            res+=closest(color[i], color[i+1]);
        }
        return res;
    }
private:
    string closest(char c1, char c2) {
        int d1=isdigit(c1)?c1-'0':c1-'a'+10;
        int d2=isdigit(c2)?c2-'0':c2-'a'+10;
        int num=d1*16+d2;
        // 00 - 17*0, 11 - 17*1, 22 - 17*2, 33 - 17*3, ...
        int index=num/17, rem=num%17;
        if (rem>17/2) index++;
        char c=index<10?index+'0':index-10+'a';
        return string(2, c);
    }
};


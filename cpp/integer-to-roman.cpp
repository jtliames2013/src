12. Integer to Roman 
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

1.
class Solution {
public:
    string intToRoman(int num) {
	string res;
	char symbol[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int scale=1000, digit;

        for (int i=0; i<7; i+=2) {
            digit=num/scale;
            if (digit>0) {
                if (digit<=3) {
                    res.append(digit, symbol[i]);
                } else if (digit==4) {
                    res.append(1, symbol[i]);
                    res.append(1, symbol[i-1]);
                } else if (digit==5) {
                    res.append(1, symbol[i-1]);
                } else if (digit<=8) {
                    res.append(1, symbol[i-1]);
                    res.append(digit-5, symbol[i]);
                } else {
                    res.append(1, symbol[i]);
                    res.append(1, symbol[i-2]);
                }
            }
            num%=scale;
            scale/=10;
        }
        return res;
    }
};

2.
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> numerals={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        for (int i=0; i<values.size(); i++) {
            int n=num/values[i];
            for (int j=0; j<n; j++) res+=numerals[i];
            num%=values[i];
        }
        
        return res;
    }
};

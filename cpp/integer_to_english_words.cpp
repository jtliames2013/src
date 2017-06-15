273. Integer to English Words 
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)

class Solution {
public:
    string convert(int part) {
        if (part==0) return "";
        else if (part<20) return underTwenty[part];
        else if (part<100) return tens[part/10] + " " + underTwenty[part%10];
        else {
            return underTwenty[part/100] + " Hundred " + convert(part%100); 
        }
    }
    
    string numberToWords(int num) {
        string res;
        if (num==0) return "Zero";
        int scale=1000000000, i=0;
        while (num>0) {
            int part=num/scale;
            if (part>0) {
                if (!res.empty()) res+=" ";
                res+=convert(part);
                if (res.back()==' ') res.pop_back();
                if (i<3) res+=" " + thousands[i];
            }
            num%=scale;
            scale/=1000;
            i++;
        }
        return res;
    }
private:
    vector<string> thousands={"Billion", "Million", "Thousand"};
    vector<string> underTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};    
};


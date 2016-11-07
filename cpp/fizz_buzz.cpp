412. Fizz Buzz   QuestionEditorial Solution  My Submissions
Total Accepted: 13776 Total Submissions: 23868 Difficulty: Easy Contributors: Admin
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i=1; i<=n; i++) {
            if (i%3!=0 && i%5!=0) res.push_back(to_string(i));
            else if (i%3==0 && i%5==0) res.push_back("FizzBuzz");
            else if (i%3==0) res.push_back("Fizz");
            else res.push_back("Buzz");
        }
        return res;
    }
};

2.
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i=1; i<=n; i++) {
            string str;
            if (i%3==0) str+="Fizz";
            if (i%5==0) str+="Buzz";
            if (str.empty()) str+=to_string(i);
            res[i-1]=str;
        }
        return res;
    }
};

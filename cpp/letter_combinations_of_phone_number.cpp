17. Letter Combinations of a Phone Number 
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Hide Company Tags Amazon Dropbox Google Uber Facebook
Hide Tags Backtracking String
Show Similar Problems

class Solution {
public:
    char getbase(char digit) {
        switch(digit) {
            case '2': return 'a';
            case '3': return 'd';
            case '4': return 'g';
            case '5': return 'j';
            case '6': return 'm';
            case '7': return 'p';
            case '8': return 't';
            case '9': return 'w';
            default: return '\0';
        }
    }
    
    bool istop(char c) {
        if (c=='c' || c=='f' || c=='i' || c=='l' ||
            c=='o' || c=='s' || c=='v' || c=='z') {
                return true;
            } else {
                return false;
            }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string output;
        std::remove(digits.begin(), digits.end(), '0');
        std::remove(digits.begin(), digits.end(), '1');
        int size=digits.size();
        int i;
        for (i=0; i<size; i++) {
            output.push_back(getbase(digits[i]));
        }
        
        i=0;
        while (1) {
            if (i==output.size()) break;
            res.push_back(output);
            
            if (!istop(output[i])) output[i]++;
            else {
                while (i<output.size()) {
                    if (!istop(output[i])) break;
                    i++;
                }
                
                if (i<output.size()) {
                    output[i]++;
                    for (int j=0; j<i; j++) {
                        output[j]=getbase(digits[j]);
                    }
                    i=0;
                }
            }
        }
        
        return res;
    }
};

2. Use recursion
class Solution {
public:
    vector<char> getChar(char digit) {
        switch (digit) {
            case '2': return {'a', 'b', 'c'}; 
            case '3': return {'d', 'e', 'f'}; 
            case '4': return {'g', 'h', 'i'}; 
            case '5': return {'j', 'k', 'l'}; 
            case '6': return {'m', 'n', 'o'}; 
            case '7': return {'p', 'q', 'r', 's'}; 
            case '8': return {'t', 'u', 'v'}; 
            case '9': return {'w', 'x', 'y', 'z'}; 
            default: return {};
        }
    }
    
    void getComb(vector<string>& res, string& digits, string& expr, int start) {
        if (start==digits.size()) {
            res.push_back(expr);
            return;
        }    
        
        vector<char> letters=getChar(digits[start]);
        for (int i=0; i<letters.size(); i++) {
            expr.push_back(letters[i]);
            getComb(res, digits, expr, start+1);
            expr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string expr;
        getComb(res, digits, expr, 0);
        
        return res;
    }
};


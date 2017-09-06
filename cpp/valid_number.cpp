65. Valid Number
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

class Solution {
public:
    bool isNumber(string s) {
        int n=s.size(), i=0;                
        for (; i<n; i++) {
            if (!isspace(s[i])) break;
        }
        bool hasPoint=false, hasE=false, numBeforeE=false, numAfterE=false;
        int start=i;
        for (; i<n; i++) {
            if (isdigit(s[i])) {
                if (!hasE) numBeforeE=true;
                else numAfterE=true;
            } else if (s[i]=='e') {
                if (hasE || numBeforeE==false) return false;
                hasE=true;
            } else if (s[i]=='.') {
                if (hasPoint || hasE) return false;
                hasPoint=true;
            } else if (s[i]=='+' || s[i]=='-') {
                if (i>start && s[i-1]!='e') return false;
            } else if (s[i]==' ') {
                while (i<n && s[i]==' ') i++;
                if (i<n) return false;
            } else {
                return false;
            }
        }
        
        return numBeforeE && (!hasE || numAfterE);
    }
};


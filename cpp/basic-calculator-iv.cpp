770. Basic Calculator IV
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]

An expression alternates chunks and symbols, with a space separating each chunk and symbol.
A chunk is either an expression in parentheses, a variable, or a non-negative integer.
A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction. For example, expression = "1 + 2 * 3" has an answer of ["7"].

The format of the output is as follows:

For each term of free variables with non-zero coefficient, we write the free variables within a term in sorted order lexicographically. For example, we would never write a term like "b*a*c", only "a*b*c".
Terms have degree equal to the number of free variables being multiplied, counting multiplicity. (For example, "a*a*b*c" has degree 4.) We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.)  A leading coefficient of 1 is still printed.
An example of a well formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 
Terms (including constant terms) with coefficient 0 are not included.  For example, an expression of "0" has an output of [].
Examples:

Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
Output: ["-1*a","14"]

Input: expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
Output: ["-1*pressure","5"]

Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
Output: ["1*e*e","-64"]

Input: expression = "7 - 7", evalvars = [], evalints = []
Output: []

Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints = []
Output: ["5*a*b*c"]

Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))",
evalvars = [], evalints = []
Output: ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
Note:

expression will have length in range [1, 250].
evalvars, evalints will have equal lengths in range [0, 100].

class Expr {
public:
    Expr operator+(const Expr& rhs) {
        Expr e;
        for (auto iter:coeff) e.update(iter.first, iter.second);
        for (auto iter:rhs.coeff) e.update(iter.first, iter.second);
        return e;
    }

    Expr operator-(const Expr& rhs) {
        Expr e;
        for (auto iter:coeff) e.update(iter.first, iter.second);
        for (auto iter:rhs.coeff) e.update(iter.first, -iter.second);
        return e;
    }
    
    Expr operator*(const Expr& rhs) {
        Expr e;
        for (auto iter1:coeff) {
            for (auto iter2:rhs.coeff) {
                multiset<string> k;
                for (auto& s:iter1.first) k.insert(s);
                for (auto& s:iter2.first) k.insert(s);
                e.update(k, iter1.second*iter2.second);
            }
        }
        return e;
    }

    Expr evaluate(unordered_map<string,int>& mp) {
        Expr e;
        for (auto iter:coeff) {
            int v=iter.second;
            multiset<string> k;
            for (auto s:iter.first) {
                if (mp.find(s)!=mp.end()) v*=mp[s];
                else k.insert(s);
            }
            e.update(k, v);
        }

        return e;
    }
    
    vector<string> toList() {
        vector<string> res;
        vector<multiset<string>> keys;
        for (auto& iter:coeff) keys.push_back(iter.first);
        auto comp=[](multiset<string>& a, multiset<string>& b) { 
            if (a.size()!=b.size()) return a.size()>b.size();
            for (auto itera=a.begin(), iterb=b.begin(); itera!=a.end(); itera++, iterb++) {
                if (*itera<*iterb) return true;
                else if (*itera>*iterb) return false;
            }
            return false;
        };
        sort(keys.begin(), keys.end(), comp);
        
        for (auto& k:keys) {
            if (coeff[k]==0) continue;
            string str;            
            str+=to_string(coeff[k]);            
            for (auto& s:k) {
                str+="*"+s;
            }
            res.push_back(str);
        }
        return res;
    }
    
    void update(multiset<string> key, int val) {
        coeff[key]+=val;
    }
    
    map<multiset<string>,int> coeff;    
};

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string,int> mp;
        for (int i=0; i<evalvars.size(); i++) {
            mp[evalvars[i]]=evalints[i];
        }
        return parse(expression).evaluate(mp).toList();
    }
    
    Expr create(string s) {
        Expr e;
        multiset<string> k;
        if (isdigit(s[0])) {
            e.update(k, stoi(s));
        } else {
            k.insert(s);
            e.update(k, 1);
        }
        return e;
    }
    
    Expr calc(Expr& lhs, Expr& rhs, char op) {
        switch (op) {
            case '+': return lhs+rhs;
            case '-': return lhs-rhs;
            case '*': return lhs*rhs;
            default: return Expr();
        }
    }
    
    Expr parse(string expression) {
        Expr e;
        vector<Expr> exprs;
        vector<char> ops;
        for (int i=0; i<expression.size(); i++) {
            if (expression[i]=='(') {
                int j=i, count=0;
                while (j<expression.size()) {
                    if (expression[j]=='(') count++;
                    else if (expression[j]==')') count--;
                    if (count==0) break;
                    j++;
                }
                exprs.push_back(parse(expression.substr(i+1, j-i-1)));
                i=j;                
            } else if (isalnum(expression[i])) {
                int j=i;
                while (j<expression.size() && isalnum(expression[j])) j++;
                exprs.push_back(create(expression.substr(i, j-i)));
                i=j;                
            } else if (expression[i]!=' ') {
                ops.push_back(expression[i]);
            }
        }
        
        for (int j=ops.size()-1; j>=0; j--) {
            if (ops[j]=='*') {
                Expr e=calc(exprs[j], exprs[j+1], ops[j]);
                ops.erase(ops.begin()+j);
                exprs.erase(exprs.begin()+j+1);
                exprs[j]=e;
            }
        }
        
        if (exprs.empty()) return Expr();
        e=exprs[0];
        for (int j=0; j<ops.size(); j++) {            
            e=calc(e, exprs[j+1], ops[j]);
        }
        
        return e;
    }
};

1096. Brace Expansion II
Hard

139

96

Add to List

Share
Under a grammar given below, strings can represent a set of lowercase words.  Let's use R(expr) to denote the set of words the expression represents.

Grammar can best be understood through simple examples:

Single letters represent a singleton set containing that word.
R("a") = {"a"}
R("w") = {"w"}
When we take a comma delimited list of 2 or more expressions, we take the union of possibilities.
R("{a,b,c}") = {"a","b","c"}
R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
Formally, the 3 rules for our grammar:

For every lowercase letter x, we have R(x) = {x}
For expressions e_1, e_2, ... , e_k with k >= 2, we have R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...
For expressions e_1 and e_2, we have R(e_1 + e_2) = {a + b for (a, b) in R(e_1) × R(e_2)}, where + denotes concatenation, and × denotes the cartesian product.
Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.

 

Example 1:

Input: "{a,b}{c,{d,e}}"
Output: ["ac","ad","ae","bc","bd","be"]
Example 2:

Input: "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation: Each distinct word is written only once in the final answer.
 

Constraints:

1 <= expression.length <= 60
expression[i] consists of '{', '}', ','or lowercase English letters.
The given expression represents a set of words based on the grammar given in the description.

Google
|
5

Adobe
|
2

https://stackoverflow.com/questions/28526013/bash-brace-expansion-algorithm

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i=0;
        auto res=dfs(expression, i);
        return vector<string>(res.begin(), res.end());
    }
private:
    set<string> dfs(string& expression, int& i) {
        set<string> res, comp;
        
        while (i<expression.size() && expression[i]!='}') {
            if (expression[i]==',') {
                // union
                for (auto& iter:comp) res.insert(iter);
                comp.clear();
                i++;
            } else {
                set<string> part;
                if (expression[i]=='{') {
                    i++; // skip {
                    part=dfs(expression, i);
                    i++; // skip }
                } else {
                    string word;
                    while (i<expression.size() && isalpha(expression[i])) word+=expression[i++];
                    part.insert(word);
                }
                
                if (comp.empty()) comp=part;
                else {
                    set<string> tmp;
                    // cartesian product
                    for (auto& it1:comp) {
                        for (auto& it2:part) tmp.insert(it1+it2);
                    }
                    swap(comp, tmp);
                }
            }
        }
        
        for (auto& iter:comp) res.insert(iter);
        return res;
    }
};

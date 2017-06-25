288. Unique Word Abbreviation  
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
Hide Company Tags Google
Hide Tags Hash Table Design
Hide Similar Problems (E) Two Sum III - Data structure design (M) Generalized Abbreviation

1) [“dog”]; isUnique(“dig”);   
//False, because “dig” has the same abbreviation with “dog" and “dog” is already in the dictionary. It’s not unique.

2) [“dog”, “dog"]; isUnique(“dog”);  
//True, because “dog” is the only word that has “d1g” abbreviation.

3) [“dog”, “dig”]; isUnique(“dog”);   
//False, because if we have more than one word match to the same abbreviation, this abbreviation will never be unique.

class ValidWordAbbr {
public:
    string getAbbr(string& s) {
        int n=s.size();
        if (n<=2) return s;
        return s[0]+to_string(n-2)+s[n-1];
    }
    
    ValidWordAbbr(vector<string> dictionary) {
        for (auto& w:dictionary) {
            if (dict.find(w)==dict.end()) {
                dict.insert(w);
                string abbr=getAbbr(w);
                mp[abbr]++;
            }
        }    
    }
    
    bool isUnique(string word) {
        string abbr=getAbbr(word);
        if (dict.find(word)==dict.end()) {
            return mp[abbr]==0;
        } else {
            return mp[abbr]==1;
        }
    }
private:
    unordered_set<string> dict;
    unordered_map<string, int> mp;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */


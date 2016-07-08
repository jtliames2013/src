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

NOTE: check if the word is in dictionary. If so, they can have the same abbreviation.

  class ValidWordAbbr {
  public:
	  unordered_map<string, int> abbrWords;
	  unordered_set<string> words;

	  string getAbbr(string s) {
		  int size=s.size();
		  int count=size>2 ? size-2 : 0;
		  string abbr;
		  abbr.push_back(s[0]);
		  if (count>0) abbr.append(to_string(count));
		  if (size>1) abbr.push_back(s[size-1]);
		  return abbr; 
	  }

      ValidWordAbbr(vector<string> &dictionary) {
    	  for (auto d:dictionary) {
    		  if (words.find(d)==words.end()) {
    			  string abbr=getAbbr(d);
    			  abbrWords[abbr]++;
    			  words.insert(d);
    		  }
    	  }
      }

      bool isUnique(string word) {
    	  string abbr=getAbbr(word);
    	  auto iter=words.find(word);
    	  if ((iter!=words.end() && abbrWords[abbr]==1) ||
    		  (iter==words.end() && abbrWords.count(abbr)==0)) {
    		  return true;
    	  }
    	  return false;
      }
  };

class ValidWordAbbr {
public:
    string getAbbr(string str) {
        int size=str.size();
        if (size<=2) return str;
        else return (str[0]+to_string(size-2)+str[size-1]);
    }
    
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto w:dictionary) {
            if (dict.find(w)==dict.end()) {
				abbr[getAbbr(w)]++;
	            dict.insert(w);
			}
        }
    }

    bool isUnique(string word) {
        string str=getAbbr(word);
        if (dict.find(word)==dict.end()) {
            return abbr.count(str)==0;
        } else {
            return abbr[str]==1;
        }
    }
private:
    unordered_map<string, int> abbr;
    unordered_set<string> dict;
};

  // Your ValidWordAbbr object will be instantiated and called as such:
  // ValidWordAbbr vwa(dictionary);
  // vwa.isUnique("hello");
  // vwa.isUnique("anotherWord");


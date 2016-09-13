383. Ransom Note  QuestionEditorial Solution  My Submissions
Total Accepted: 16159 Total Submissions: 36348 Difficulty: Easy
 B
Given �
 an   
arbitrary �
 ransom �
 note m
 string  �
and   
another  �
string  �
containing  8
letters from 

 all   
the   
magazines, �
 write  �
a  

function  �
that   
will   
return  �
true   
if   
the   
ransom  �
 note   
can   
be   
constructed  

from   
the   
magazines ;  

otherwise,   
it   
will   
return  �
false.  �
 B


Each   
letter  
 in e
 the r
 magazine  �
string  �
can n
 only   
be 

 used   
once  
 in  
 your   
ransom  
 note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
Subscribe to see which companies asked this question

Hide Tags String

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> count;
        for (auto letter:magazine) {
            count[letter]++;
        }
        
        for (auto letter:ransomNote) {
            if (count.find(letter)==count.end() || count[letter]<=0) {
                return false;
            }    
            count[letter]--;
        }
        
        return true;
    }
};

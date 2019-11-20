1178. Number of Valid Words for Each Puzzle
Hard

126

9

Favorite

Share
With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:
word contains the first letter of puzzle.
For each letter in word, that letter is in puzzle.
For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).
Return an array answer, where answer[i] is the number of words in the given word list words that are valid with respect to the puzzle puzzles[i].
 

Example :

Input: 
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
Output: [1,1,3,2,4,0]
Explanation:
1 valid word for "aboveyz" : "aaaa" 
1 valid word for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for "absoryz" : "aaaa", "asas"
4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
There're no valid words for "gaswxyz" cause none of the words in the list contains letter 'g'.
 

Constraints:

1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] are English lowercase letters.
Each puzzles[i] doesn't contain repeated characters.


The idea behind this puzzle is to generate a set of the characters in every word, and for every puzzle, count how many words' sets are strict subsets of the puzzle's set.

To do so, we have to generate a way to represent the unique set of a given word. One way to do so is to create a bit mask, where the i-th bit being 1 means the i-th character in the alphabet is in the given word (implemented at [1]). For example, because the word 'apple' is composed of the characters a, e, l, p, it would have a key as follows:

0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1
z y x w v u t s r q p o n m l k j i h g f e d c b a
The alphabet is to show the mapping between characters and their position in the bit mask. In this example, the words 'appppppple' and 'pale' would have the same bit mask.

Then in [2] we create a mapping from a bit mask to the count of words that generate that bit mask.

Next, for every puzzle, we need to see what words are composed of characters that only exist in puzzle. So if puzzle is 'abd', then 'ba' would count but 'bc' would not because 'c' is not in 'abd'. To do so, we want to generate every possible set of characters that is a strict subset of the characters in puzzle. In the previous example, this would be [a], [b], [d], [a,b], [a,d], [b,d], [a,b,d]. In bitwise terms, this means we need to generate every "submask", s, where the bits in s are also in puzzle's mask. For example, the puzzle 'abd' would have the bitmask 1011, and every submask would be 0000, 0001, 0010, 1000, 1001, 1010, 0011, 1011. We generate every submask by taking advantage of subtracting by 1, which in base 2 flips the lowest bit to 0, and flips all bits to the right of that to 1. By subtracting by 1 and bitwise and-ing with the original mask, we turn off every bit one-by-one. For puzzle with mask 1011, this would go as follows:

subMask = originalMask = 1011 // [d, b, a]
(subMask - 1) & originalMask = (1011 - 1) & 1011 = 1010 & 1011 = 1010 // [d, b]
(subMask - 1) & originalMask = (1010 - 1) & 1011 = 1001 & 1011 = 1001 // [d, a]
(subMask - 1) & originalMask = (1001 - 1) & 1011 = 1000 & 1011 = 1000 // [d]
(subMask - 1) & originalMask = (1000 - 1) & 1011 = 0111 & 1011 = 0011 // [b, a]
(subMask - 1) & originalMask = (0011 - 1) & 1011 = 0010 & 1011 = 0010 // [b]
(subMask - 1) & originalMask = (0010 - 1) & 1011 = 0001 & 1011 = 0001 // [a]
(subMask - 1) & originalMask = (0001 - 1) & 1011 = 0000 & 1011 = 0000 // []
We implement generating every submask in [3].

Finally, for every submask, we also have to ensure that the first letter in the puzzle is in the word. To accomplish this, if the puzzle's first letter is the i-th character in the alphabet, we check if the submask has its i-th bit flipped [4]. If it contains it, it's a valid word and we add the count of words corresponding to that bit mask to our total for this puzzle.

Once we've added the total number of words that correspond to every submask for a puzzle, we have the solution for that puzzle. We then repeat the task for every puzzle and we have the solution.

   
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto& w:words) {
            int mask=0;
            for (auto c:w) {
                mask|=(1<<(c-'a'));
            }
            mp[mask]++;
        }
        
        for (auto& p:puzzles) {
            int mask=0;
            for (auto c:p) {
                mask|=(1<<(c-'a'));
            }
            int count=0, sub=mask, first=(1<<(p[0]-'a'));
            while (sub) {
                if ((sub & first)==first && mp.find(sub)!=mp.end()) {
                    count+=mp[sub];
                }
                sub=(sub-1)&mask;
            }
            res.push_back(count);
        }
        
        return res;
    }
};
 

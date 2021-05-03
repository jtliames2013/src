1813. Sentence Similarity III
Medium

101

24

Add to List

Share
A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.

Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.

Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
Output: true
Explanation: sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"
Output: false
Explanation: No single sentence can be inserted inside one of the sentences to make it equal to the other.
Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"
Output: true
Explanation: sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.
Example 4:

Input: sentence1 = "Luky", sentence2 = "Lucccky"
Output: false
 

Constraints:

1 <= sentence1.length, sentence2.length <= 100
sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
The words in sentence1 and sentence2 are separated by a single space.

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n1=sentence1.size(), n2=sentence2.size();
        vector<string> s1, s2;
        for (int i=0; i<n1; ) {
            if (sentence1[i]==' ') i++;
            else {
                int j=i;
                while (j<n1 && sentence1[j]!=' ') j++;
                s1.push_back(sentence1.substr(i, j-i));
                i=j;
            }
        }
        for (int i=0; i<n2; ) {
            if (sentence2[i]==' ') i++;
            else {
                int j=i;
                while (j<n2 && sentence2[j]!=' ') j++;
                s2.push_back(sentence2.substr(i, j-i));
                i=j;
            }
        }

        n1=s1.size(), n2=s2.size();
        if (n1<n2) return areSentencesSimilar(sentence2, sentence1);
        
        int i=0;
        while (i<n2 && s1[i]==s2[i]) i++;
        while (i<n2 && s1[n1-n2+i]==s2[i]) i++;
        return i==n2;
    }
};


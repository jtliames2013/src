843. Guess the Word
Hard

314

337

Favorite

Share
This problem is an interactive problem new to the LeetCode platform.

We are given a word list of unique words, each word is 6 letters long, and one word in this list is chosen as secret.

You may call master.guess(word) to guess a word.  The guessed word should have type string and must be from the original list with 6 lowercase letters.

This function returns an integer type, representing the number of exact matches (value and position) of your guess to the secret word.  Also, if your guess is not in the given wordlist, it will return -1 instead.

For each test case, you have 10 guesses to guess the word. At the end of any number of calls, if you have made 10 or less calls to master.guess and at least one of these guesses was the secret, you pass the testcase.

Besides the example test case below, there will be 5 additional test cases, each with 100 words in the word list.  The letters of each word in those testcases were chosen independently at random from 'a' to 'z', such that every word in the given word lists is unique.

Example 1:
Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

Explanation:

master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6 matches.
master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
master.guess("abcczz") returns 4, because "abcczz" has 4 matches.

We made 5 calls to master.guess and one of them was the secret, so we pass the test case.
Note:  Any solutions that attempt to circumvent the judge will result in disqualification.

We start by taking all words as potential candidates. If we guess a word, we're given its distance from the secret, which allows us to eliminate words whose distance from the guess is different. That is, if we know that the secret is 4 characters away from the guess, then we can eliminate all words whose distance from the guess is not 4, because they can't be the secret.

In order to maximize the number of words we eliminate at each guess, we choose a guess that partitions the potential candidate set roughly equally by all possible distances. That is, if we choose a guess that's roughly equally at distance 0 from 1/6 of all words, distance 1 from 1/6 of all words, etc., we know that whatever distance the secret happens to be from the guess, we can eliminate a substantial number of words. This is where we use a MinMax heuristic. For each word, we compute a histogram of its distance from every word in the candidate set, and then select the word whose histogram peak (max) is smallest (min). That property guarantees that the selected word partitions the candidate set well by distance and that it has the potential to eliminate the maximum number of elements. That's the word we choose as a guess. Once we offer it and obtain its distance from the secret, then we can eliminate all candidates that don't have the same distance to it.

We repeat the same process iteratively, taking words from the full word set, but compute the histogram of their distances to the reduced candidate set only. The reason is that a word that is bad at partitioning the full word set may be good at partitioning the reduced candidate set at a later iteration. Choosing guess words from the full set also allows us to avoid falling into a local optimum valley where the reduced candidate set contains only words that partition it very poorly.

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {    
public:
    void findSecretWord(vector<string>& wordlist, Master& master) 
    {        
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        while (st.size()>1) {            
            string guessWord = patition(wordlist, st);        
            int d=master.guess(guessWord);
            if (d==guessWord.size()) return;

            // Eliminate words whose distance != d
            for (auto it=st.begin(); it!=st.end();) {
                if (dist(guessWord, *it)!=d) {
                    it=st.erase(it);
                } else {
                    ++it;
                }
            }
        }
        if (!st.empty()) {
            master.guess(*st.begin());
        }
    }
private:
    int dist(const string& a, const string& b) {        
        int dist = 0;
        for (int i=0; i<a.size(); ++i) {
            dist+=a[i]==b[i];
        }
        return dist;
    }
    
    int maxDistCount(string& word, unordered_set<string>& st) {
        vector<int> hist(word.size()+1);    
        for (auto& s:st) hist[dist(word, s)]++;
        return *max_element(hist.begin(), hist.end());
    }
    
    string patition(vector<string>& wordlist, unordered_set<string>& st) {
        string res;
        int minMax=wordlist.size();
        for (auto w:wordlist) {
            int cnt=maxDistCount(w, st);
            if (cnt<minMax) {
                minMax=cnt;
                res=w;
            }
        }
        return res;
    }
};

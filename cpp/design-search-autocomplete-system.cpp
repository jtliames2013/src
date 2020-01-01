642. Design Search Autocomplete System
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
The system have already tracked down the following sentences and their corresponding times: 
"i love you" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love leetcode" : 2 times 
Now, the user begins another search: 

Operation: input('i') 
Output: ["i love you", "island","i love leetcode"] 
Explanation: 
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored. 

Operation: input(' ') 
Output: ["i love you","i love leetcode"] 
Explanation: 
There are only two sentences that have prefix "i ". 

Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a". 

Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search. 

Note:
The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.

Amazon
|
14

Google
|
9

Dropbox
|
7

Facebook
|
3

Uber
|
3

Microsoft
|
3

Snapchat
|
2

Lyft
|
5

Salesforce
|
2

Bloomberg
|
2

Apple
|
2

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;
    TrieNode(): count(0) {}
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word, int cnt) {
        TrieNode* n=root;
        for (int i=0; i<word.size(); ++i) {
            if (n->children.find(word[i])==n->children.end()) {
                n->children[word[i]]=new TrieNode();
            }
            n=n->children[word[i]];
        }
        n->count+=cnt;
    }
    
    vector<pair<string, int>> getWords(string prefix) {
        vector<pair<string, int>> res;
        TrieNode* n=root;
        for (int i=0; i<prefix.size(); ++i) {
            if (n->children.find(prefix[i])==n->children.end()) return res;
            n=n->children[prefix[i]];
        }

        dfs(res, n, prefix);
        return res;
    }
private:
    void dfs(vector<pair<string, int>>& res, TrieNode* n, string word) {
        if (n==NULL) return;
        if (n->count>0) res.push_back({word, n->count});
        for (auto& iter:n->children) dfs(res, iter.second, word+iter.first);
    }

    TrieNode* root;
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        K=3;
        for (int i=0; i<sentences.size(); ++i) {
            trie.insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> res;
        if (c=='#') {
            trie.insert(prefix, 1);
            prefix="";
            return res;
        }
        
        prefix+=c;
        vector<pair<string, int>> words=trie.getWords(prefix);
        auto comp=[](pair<string, int>& a, pair<string, int>& b){ return a.second>b.second || (a.second==b.second && a.first<b.first); };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        for (auto& w:words) {
            if (pq.size()<K) pq.push(w);
            else{
                if (w.second>pq.top().second || (w.second==pq.top().second && w.first<pq.top().first)) {
                    pq.pop();
                    pq.push(w);
                }
            }
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
private:
    int K;
    Trie trie;
    string prefix;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


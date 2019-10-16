433. Minimum Genetic Mutation
Medium

305

37

Favorite

Share
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
 

Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
 

Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
 

Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int res=0;
        if (start==end) return 0;
        unordered_set<string> st(bank.begin(), bank.end());
        queue<string> q;
        q.push(start);
        while (!q.empty()) {
            int size=q.size();
            for (int i=0; i<size; ++i) {
                auto f=q.front();
                q.pop();
            
                for (int i=0; i<f.size(); ++i) {
                    for (char c:{'A', 'C', 'G', 'T'}) {
                        string str=f;
                        if (str[i]!=c) {
                            str[i]=c;
                            if (st.find(str)!=st.end()) {
                                if (str==end) return res+1;
                                q.push(str);
                                st.erase(str);
                            }
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};

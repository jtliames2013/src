752. Open the Lock
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.

1. BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {        
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        string start="0000";
        if (st.find(start)!=st.end() || st.find(target)!=st.end()) return -1;
        if (start==target) return 0;
        
        q.push(start);
        visited.insert(start);
        int res=1;
        while (!q.empty()) {
            int n=q.size();
            for (int i=0; i<n; i++) {
                string f=q.front();
                q.pop();
                vector<string> neighbors=getNeighbors(f);
                for (auto neighbor:neighbors) {
                    if (neighbor==target) return res;
                    if (visited.find(neighbor)==visited.end() && st.find(neighbor)==st.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            res++;
        }
        return -1;
    }
private:
    vector<string> getNeighbors(string& s) {
        vector<string> res;
        for (int i=0; i<s.size(); i++) {
            string str=s;
            str[i]=(str[i]-'0'+1)%10+'0';
            res.push_back(str);
        }
        for (int i=0; i<s.size(); i++) {
            string str=s;
            str[i]=(str[i]-'0'-1+10)%10+'0';
            res.push_back(str);
        }
        return res;
    }
};

2. Bi-directional BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {        
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> visited, q1, q2;
        string start="0000";
        if (st.find(start)!=st.end() || st.find(target)!=st.end()) return -1;
        if (start==target) return 0;
        
        q1.insert(start);
        visited.insert(start);
        q2.insert(target);
        visited.insert(target);
        return bfs(q1, q2, st, visited, 1);
    }
private:
    int bfs(unordered_set<string>& q1, unordered_set<string>& q2, unordered_set<string>& st, unordered_set<string>& visited, int turns) {
        if (q1.empty()) return -1;
        if (q1.size()>q2.size()) {
            return bfs(q2, q1, st, visited, turns);
        }
        
        unordered_set<string> next;
        for (auto str:q1) {
            vector<string> neighbors=getNeighbors(str);
            for (auto neighbor:neighbors) {
                if (q2.find(neighbor)!=q2.end()) return turns;
                if (visited.find(neighbor)==visited.end() && st.find(neighbor)==st.end()) {
                    next.insert(neighbor);
                    visited.insert(neighbor);
                }
            }            
        }
        swap(q1, next);
        next.clear();
        return bfs(q1, q2, st, visited, turns+1);
    }
    
    vector<string> getNeighbors(string& s) {
        vector<string> res;
        for (int i=0; i<s.size(); i++) {
            string str=s;
            str[i]=(str[i]-'0'+1)%10+'0';
            res.push_back(str);
        }
        for (int i=0; i<s.size(); i++) {
            string str=s;
            str[i]=(str[i]-'0'-1+10)%10+'0';
            res.push_back(str);
        }
        return res;
    }
};



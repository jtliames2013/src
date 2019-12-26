294. Flip Game II 
 You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity. 

Google
|
LeetCode

class Solution {
public:
    bool canWin(string s) {
        int n=s.size();
        for (int i=0; i<n-1; i++) {
            if (s[i]=='+' && s[i+1]=='+') {
                string str=s;
                str[i]=str[i+1]='-';
                if (!canWin(str)) return true;
            }
        }
        return false;
    }
};

2. pass reference
class Solution {
public:
    bool canWin(string s) {
        return dfs(s);   
    }
    
    bool dfs(string& s) {
        int n=s.size();
        for (int i=0; i<n-1; i++) {
            if (s[i]=='+' && s[i+1]=='+') {
                s[i]=s[i+1]='-';
                bool b=dfs(s);
                s[i]=s[i+1]='+';
                if (!b) return true;
            }
        }
        return false;
    }
};


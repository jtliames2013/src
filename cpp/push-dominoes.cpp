838. Push Dominoes
DescriptionHintsSubmissionsDiscussSolution
There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.



After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Note:

0 <= N <= 10^5
String dominoes contains only 'L', 'R' and '.'

1.
class Solution {
public:
    string pushDominoes(string dominoes) {        
        string res=dominoes;
        int n=dominoes.size();
        if (n==0) return res;        
        vector<int> dist(n, INT_MAX);
        if (dominoes[0]!='.') dist[0]=0;
        for (int i=1; i<n; ++i) {
            if (dominoes[i]!='.') dist[i]=0;
            else {
                if (res[i-1]=='R') {
                    res[i]=res[i-1];
                    dist[i]=dist[i-1]+1;
                }
            }
        }
        for (int i=n-2; i>=0; --i) {
            if (res[i+1]=='L') {
                if (dist[i]>dist[i+1]+1) {
                    dist[i]=dist[i+1]+1;
                    res[i]=res[i+1];
                } else if (dist[i]==dist[i+1]+1) {
                    res[i]='.';
                }
            }    
        }
        
        return res;
    }
};

2.
class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        dominoes="L"+dominoes+"R";
        int n=dominoes.size();
        for (int l=0, r=1; r<n; ++r) {
            if (dominoes[r]=='.') continue;
            int len=r-l-1;
            if (l>0) res+=dominoes[l];            
            if (dominoes[l]==dominoes[r]) res.append(len, dominoes[l]);
            else if (dominoes[l]=='L' && dominoes[r]=='R') res.append(len, '.');
            else {
                res.append(len/2, 'R');
                if (len%2!=0) res+='.';
                res.append(len/2, 'L');
            } 
            l=r;
        }
        
        return res;
    }
};

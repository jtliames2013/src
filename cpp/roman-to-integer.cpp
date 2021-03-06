13. Roman to Integer 
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

1.
class Solution {
public:
    int romanToInt(string s) {
        int res=0, n=s.size();
        for (int i=0; i<n; i++) {
            if (s[i]=='M') res+=1000;
            else if (s[i]=='C') {
                if (i<n-1 && s[i+1]=='D') {
                    res+=400;
                    i++;
                } else if (i<n-1 && s[i+1]=='M') {
                    res+=900;
                    i++;
                } else res+=100;
            } else if (s[i]=='X') {
                if (i<n-1 && s[i+1]=='L') {
                    res+=40;
                    i++;
                } else if (i<n-1 && s[i+1]=='C') {
                    res+=90;
                    i++;
                } else res+=10;
            } else if (s[i]=='I') {
                if (i<n-1 && s[i+1]=='V') {
                    res+=4;
                    i++;
                } else if (i<n-1 && s[i+1]=='X') {
                    res+=9;
                    i++;
                } else res+=1;
            } 
            else if (s[i]=='D') res+=500;
            else if (s[i]=='L') res+=50;
            else if (s[i]=='V') res+=5;
        }
        
        return res;
    }
};

2.
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp={{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res=0;
        int n=s.size();
        for (int i=0; i<n-1; i++) {
            if (mp[s[i]]<mp[s[i+1]]) res-=mp[s[i]];
            else res+=mp[s[i]];
        }
        return res+mp[s[n-1]];
    }
};

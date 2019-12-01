906. Super Palindromes
Hard

60

142

Favorite

Share
Let's say a positive integer is a superpalindrome if it is a palindrome, and it is also the square of a palindrome.

Now, given two positive integers L and R (represented as strings), return the number of superpalindromes in the inclusive range [L, R].

 

Example 1:

Input: L = "4", R = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
 

Note:

1 <= len(L) <= 18
1 <= len(R) <= 18
L and R are strings representing integers in the range [1, 10^18).
int(L) <= int(R)


class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int res=0, bound=100000; // len(L) and len(R)<=18
        unsigned long long lb=stoull(L), rb=stoull(R);
        for (int i=1; i<bound; ++i) {
            string l=to_string(i), r=l;
            reverse(r.begin(), r.end());
            l+=r.substr(1);
            unsigned long long num=stoull(l);
            num*=num;
            if (num>rb) break;
            if (num>=lb && isPalin(num)) res++;
        }

        for (int i=1; i<bound; ++i) {
            string l=to_string(i), r=l;
            reverse(r.begin(), r.end());
            l+=r;
            unsigned long long num=stoull(l);
            num*=num;
            if (num>rb) break;
            if (num>=lb && isPalin(num)) res++;
        }
        
        return res;
        
    }
private:
    bool isPalin(unsigned long long n){
        unsigned long long x=n, r=0;
        while (x>0) {
            r=r*10+x%10;
            x/=10;
        }
        return n==r;
    }
};

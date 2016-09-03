372. Super Pow  
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024

One knowledge: ab % k = (a%k)(b%k)%k
Since the power here is an array, we'd better handle it digit by digit.
One observation:
a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
Looks complicated? Let me put it other way:
Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
f(a,1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456),10) * f(a,7)%k;
Implementation of this idea:

class Solution {
public:
    int powermod(int a, int n) {
        // prevent res*LONG_MAX overflow
        a%=base;
        int res=1;
        for (int i=0; i<n; i++) {
            res = (res*a)%base;
        }
        return res%base;
    }
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int n=b.back();
        b.pop_back();
        return powermod(superPow(a, b),10)*powermod(a, n)%base;
    }
private:
    const int base=1337;
};

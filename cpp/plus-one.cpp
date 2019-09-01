66. Plus One 
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Hide Company Tags Google
Hide Tags Array Math
Hide Similar Problems (M) Multiply Strings (E) Add Binary (M) Plus One Linked List

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for (int i=n-1; i>=0; i--) {
            if (digits[i]<9) {
                digits[i]++;
                return digits;
            } else {
                digits[i]=0;
            }
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


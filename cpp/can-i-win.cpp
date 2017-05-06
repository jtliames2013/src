464. Can I Win Add to List
DescriptionHintsSubmissionsSolutions
Total Accepted: 8749
Total Submissions: 36703
Difficulty: Medium
Contributors:
taylorty
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.
Subscribe to see which companies asked this question.

Hide Tags Dynamic Programming Minimax
Hide Similar Problems (M) Flip Game II (M) Guess Number Higher or Lower II (M) Predict the Winner

class Solution {
public:
    int getKey(vector<bool>& choosed) {
        int num=0;
        for (auto b:choosed) {
            if (b) num|=1;
            num<<=1;
        }
        return num;
    }
    bool canIWin(vector<bool>& choosed, int target, unordered_map<int,bool>& res) {
        int key=getKey(choosed);
        if (res.find(key)!=res.end()) return res[key];
        
        for (int i=0; i<choosed.size(); i++) {
            if (!choosed[i]) {
                if (i+1>=target) return true;
                choosed[i]=true;
                bool b=canIWin(choosed, target-(i+1), res);
                choosed[i]=false;
                if (!b) {
                    res[key]=true;
                    return true;
                }
            }
        }
        
        res[key]=false;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal) return false;
        vector<bool> choosed(maxChoosableInteger);
        unordered_map<int,bool> res;
        return canIWin(choosed, desiredTotal, res);
    }
};

After solving several "Game Playing" questions in leetcode, I find them to be pretty similar. Most of them can be solved using the top-down DP approach, which "brute-forcely" simulates every possible state of the game.

The key part for the top-down dp strategy is that we need to avoid repeatedly solving sub-problems. Instead, we should use some strategy to "remember" the outcome of sub-problems. Then when we see them again, we instantly know their result. By doing this, we can always reduce time complexity from exponential to polynomial.
(EDIT: Thanks for @billbirdh for pointing out the mistake here. For this problem, by applying the memo, we at most compute for every subproblem once, and there are O(2^n) subproblems, so the complexity is O(2^n) after memorization. (Without memo, time complexity should be like O(n!))

For this question, the key part is: what is the state of the game? Intuitively, to uniquely determine the result of any state, we need to know:

The unchosen numbers
The remaining desiredTotal to reach
A second thought reveals that 1) and 2) are actually related because we can always get the 2) by deducting the sum of chosen numbers from original desiredTotal.

Then the problem becomes how to describe the state using 1).

In my solution, I use a boolean array to denote which numbers have been chosen, and then a question comes to mind, if we want to use a Hashmap to remember the outcome of sub-problems, can we just use Map<boolean[], Boolean> ? Obviously we cannot, because the if we use boolean[] as a key, the reference to boolean[] won't reveal the actual content in boolean[].

Since in the problem statement, it says maxChoosableInteger will not be larger than 20, which means the length of our boolean[] array will be less than 20. Then we can use an Integer to represent this boolean[] array. How?

Say the boolean[] is {false, false, true, true, false}, then we can transfer it to an Integer with binary representation as 00110. Since Integer is a perfect choice to be the key of HashMap, then we now can "memorize" the sub-problems using Map<Integer, Boolean>.

The rest part of the solution is just simulating the game process using the top-down dp.


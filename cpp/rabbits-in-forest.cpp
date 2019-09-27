781. Rabbits in Forest
DescriptionHintsSubmissionsDiscussSolution
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
Note:

answers will have length at most 1000.
Each answers[i] will be an integer in the range [0, 999].

If x+1 rabbits have same color, then we get x+1 rabbits who all answer x.
now n rabbits answer x.
If n % (x + 1) == 0, we need n / (x + 1) groups of x + 1 rabbits.
If n % (x + 1) != 0, we need n / (x + 1) + 1 groups of x + 1 rabbits.

the number of groups is math.ceil(n / (x + 1)) and it equals to (n + x) / (x + 1) , which is more elegant.

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res=0;
        unordered_map<int,int> mp;
        for (auto a:answers) mp[a]++;
        
        for (auto iter:mp) {
            int div=iter.second/(iter.first+1);
            int mod=iter.second%(iter.first+1);
            res+=((mod==0)?div:div+1)*(iter.first+1);
        }
        return res;
    }
};

2.
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res=0;
        unordered_map<int,int> mp;
        for (auto a:answers) mp[a]++;

        for (auto iter:mp) {
            res+=(iter.second+iter.first)/(iter.first+1)*(iter.first+1);
        }
        return res;
    }
};

3.
Count when you first see the number(say we see this color for the first time so res += num+1), and once num+1 rabbits say num, we have completed a group so we should remove this color

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res=0;
        unordered_map<int,int> mp;
        for (auto a:answers) {
            mp[a]++;
            if (mp[a]==1) res+=a+1;
            if (mp[a]>a) mp.erase(a);
        }
        return res;
    }
};

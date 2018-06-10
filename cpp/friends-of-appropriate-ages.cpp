825. Friends Of Appropriate Ages
DescriptionHintsSubmissionsDiscussSolution
Some people will make friend requests. The list of their ages is given and ages[i] is the age of the ith person. 

Person A will NOT friend request person B (B != A) if any of the following conditions are true:

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
Otherwise, A will friend request B.

Note that if A requests B, B does not necessarily request A.  Also, people will not friend request themselves.

How many total friend requests are made?

Example 1:

Input: [16,16]
Output: 2
Explanation: 2 people friend request each other.
Example 2:

Input: [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
Example 3:

Input: [20,30,100,110,120]
Output: 
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 

Notes:

1 <= ages.length <= 20000.
1 <= ages[i] <= 120.

1.
class Solution {
public:
    bool request(int a, int b) {
        return !(b<=0.5*a+7 || b>a);
    }
    
    int numFriendRequests(vector<int>& ages) {   
        int res=0;
        unordered_map<int,int> mp;
        for (auto a:ages) mp[a]++;
        for (auto a:mp) {
            for (auto b:mp) {                
                if (request(a.first, b.first)) {
                    res+=a.second*(b.second-(a.first==b.first?1:0));
                }
            }
        }
        return res;
    }
};

2.
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res=0, sum=0;
        map<int,int> mp;
        for (auto a:ages) mp[a]++;
        for (auto l=mp.begin(), r=mp.begin(); r!=mp.end(); ++r) {
            sum+=r->second;
            while (l->first<=r->first && l->first<=r->first*0.5+7) {
                sum-=l->second;
                ++l;
            }
            if (sum>0) res+=r->second*(sum-1);
        }
        return res;
    }
};

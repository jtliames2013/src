134. Gas Station  QuestionEditorial Solution  My Submissions
Total Accepted: 68549 Total Submissions: 244616 Difficulty: Medium
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Subscribe to see which companies asked this question

Hide Tags Greedy

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        if (n==0) return -1;
        vector<int> diff(n, 0);
        for (int i=0; i<n; i++) {
            diff[i]=gas[i]-cost[i];
        }
        
        int total=0, sum=0, start=0;
        for (int i=0; i<n; i++) {
            total+=diff[i];
            sum+=diff[i];
            if (sum<0) { 
                start=i+1;
                sum=0;
            }
        }
        
        if (total<0) return -1;
        else return start;
    }
};


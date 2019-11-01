857. Minimum Cost to Hire K Workers
Hard

644

67

Favorite

Share
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
 

Note:

1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.

We sort workers based on their expect values. Say we are at worker i and want to form a k-group and we already know it would cost sum*expect[i]. To pay the minimum money we should minimum the sum, which can be found using a maxHeap (to replace the max value with a smaller one) to keep the smaller q's as we move forward.

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res=DBL_MAX;
        int n=quality.size(), sum=0;
        vector<pair<double, int>> worker(n);
        for (int i=0; i<n; ++i) {
            worker[i]={(double)wage[i]/quality[i], quality[i]};
        }
        sort(worker.begin(), worker.end());
        
        priority_queue<int> pq;        
        for (auto w:worker) {
            sum+=w.second;
            pq.push(w.second);
            if (pq.size()>K) {
                sum-=pq.top();
                pq.pop();
            }
            if (pq.size()==K) {
                res=min(res, sum*w.first);
            }            
        }
        return res;
    }
};

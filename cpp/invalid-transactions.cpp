1169. Invalid Transactions
Medium

26

328

Favorite

Share
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
Each transaction string transactions[i] consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.

Given a list of transactions, return a list of transactions that are possibly invalid.  You may return the answer in any order.

 

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
Example 2:

Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]
Example 3:

Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
 

Constraints:

transactions.length <= 1000
Each transactions[i] takes the form "{name},{time},{amount},{city}"
Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
Each {time} consist of digits, and represent an integer between 0 and 1000.
Each {amount} consist of digits, and represent an integer between 0 and 2000.

class Solution {
public:
    struct Info {
        int time;
        int amount;
        string city;        
    };
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_set<string> res;
        unordered_map<string, vector<Info>> mp;
        for (auto& t:transactions) {
            istringstream iss(t);            
            string name, time, amount;
            Info i;
            getline(iss, name, ',');
            getline(iss, time, ',');
            i.time=stoi(time);
            getline(iss, amount, ',');
            i.amount=stoi(amount);
            getline(iss, i.city, ',');            
            
            if (i.amount>=1000) res.insert(t);
            bool invalid=false;
            for (auto iter=mp[name].begin(); iter!=mp[name].end(); ++iter) {
                if (abs(iter->time-i.time)<=60 && iter->city!=i.city) {
                    res.insert(name+","+to_string(iter->time)+","+to_string(iter->amount)+","+iter->city);
                    invalid=true;
                }
            }
            mp[name].push_back(i);
            if (invalid) res.insert(t);
        }
        return vector<string>(res.begin(), res.end());
    }
};

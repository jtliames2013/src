355. Design Twitter 
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
Hide Company Tags Amazon Twitter
Hide Tags Hash Table Heap Design

class Compare {
public:
    bool operator()(pair<list<pair<int,int>>::iterator,int> a, pair<list<pair<int,int>>::iterator,int> b) {
        return a.first->first < b.first->first;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        feeds[userId].push_front({time++, tweetId});
        if (feeds[userId].size()>10) feeds[userId].pop_back();
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<list<pair<int,int>>::iterator,int>, vector<pair<list<pair<int,int>>::iterator,int>>, Compare> pq;
        if (!feeds[userId].empty()) pq.push({feeds[userId].begin(), userId});
        for (auto f:followees[userId]) {
            if (!feeds[f].empty()) pq.push({feeds[f].begin(), f});
        }
        
        int count=0;
        while (!pq.empty() && count<10) {
            pair<list<pair<int,int>>::iterator,int> t=pq.top();
            pq.pop();
            count++;
            res.push_back(t.first->second);
            t.first++;
            if (t.first!=feeds[t.second].end()) pq.push({t.first, t.second});
        }
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId!=followeeId) {
            followees[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId!=followeeId) {
            followees[followerId].erase(followeeId);
        }
    }
private:
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, list<pair<int,int>>> feeds;
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */


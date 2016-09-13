public class Twitter {
    class Tweet {
        int time;
        int id;
        Tweet(int t, int i) {
            time=t;
            id=i;
        }
    }
    class Pos {
        List<Tweet> list;
        int index;
        Pos(List<Tweet> l, int i) {
            list=l;
            index=i;
        }
    }

    Map<Integer, TreeSet<Integer>> followees;
    Map<Integer, List<Tweet>> tweets;
    int time;
    
    /** Initialize your data structure here. */
    public Twitter() {
        followees=new HashMap<Integer, TreeSet<Integer>>();
        tweets=new HashMap<Integer, List<Tweet>>();
        time=0;
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        if (!tweets.containsKey(userId)) {
            tweets.put(userId, new ArrayList<Tweet>());
        }
        tweets.get(userId).add(0, new Tweet(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res=new ArrayList<Integer>();
        PriorityQueue<Pos> pq=new PriorityQueue<Pos>(new Comparator<Pos>() {
            @Override
            public int compare(Pos a, Pos b) {
                return b.list.get(b.index).time-a.list.get(a.index).time;
            }
        });
        
        if (followees.containsKey(userId)) {
            for (int id:followees.get(userId)) {
                if (tweets.containsKey(id) && !tweets.get(id).isEmpty()) {
                    pq.offer(new Pos(tweets.get(id), 0));
                }
            }
        }
        
        int count=0;
        while (!pq.isEmpty() && count<10) {
            Pos p=pq.poll();
            count++;
            res.add(p.list.get(p.index).id);
            if (p.index+1<p.list.size()) {
                pq.offer(new Pos(p.list, p.index+1));
            }
        } 
        
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (!followees.containsKey(followerId)) {
            followees.put(followerId, new TreeSet<Integer>());
        }
        followees.get(followerId).add(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (followees.containsKey(followerId) && followerId!=followeeId) {
            followees.get(followerId).remove(followeeId);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

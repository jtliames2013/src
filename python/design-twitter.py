class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time=itertools.count(step=-1)
        self.followees=collections.defaultdict(set)
        self.feeds=collections.defaultdict(collections.deque)

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.feeds[userId].appendleft((next(self.time), tweetId))
        if len(self.feeds[userId])>10: self.feeds[userId].pop()

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        feeds=heapq.merge(*(self.feeds[u] for u in (self.followees[userId] | {userId})))
        return [id for _, id in itertools.islice(feeds, 10)]

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId!=followeeId:
            self.followees[followerId].add(followeeId)

    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """        
        if followerId!=followeeId:
            self.followees[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)

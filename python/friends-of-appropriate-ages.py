class Solution:
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        def request(a, b):
            return not (b<=a*0.5+7 or b>a)
        c=collections.Counter(ages)
        return sum(c[a]*(c[b]-(a==b)) if request(a, b) else 0 for a in c for b in c)

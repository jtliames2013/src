class Solution:
    def flipgame(self, fronts, backs):
        """
        :type fronts: List[int]
        :type backs: List[int]
        :rtype: int
        """
        st={f for f, b in zip(fronts, backs) if f==b}
        return min([i for i in fronts+backs if i not in st] or [0])


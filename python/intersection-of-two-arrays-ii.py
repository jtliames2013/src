class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        n1, n2=map(collections.Counter, (nums1, nums2))
        return list((n1 & n2).elements())

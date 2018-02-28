class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        n1=set(nums1)
        n2=set(nums2)
        return list(n1 & n2)

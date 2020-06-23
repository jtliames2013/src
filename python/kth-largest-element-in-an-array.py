class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(l, r, pivot):
            nums[pivot], nums[r]=nums[r], nums[pivot]
            end=l
            for i in range(l, r):
                if nums[i]>nums[r]:
                    if end!=i: nums[end], nums[i]=nums[i], nums[end]
                    end+=1
            nums[end], nums[r]=nums[r], nums[end]
            return end
        l, r=0, len(nums)-1
        while True:
            pivot=random.randint(l, r)
            pivot=partition(l, r, pivot)
            if pivot==k-1: return nums[pivot]
            elif pivot<k-1: l=pivot+1
            else: r=pivot-1


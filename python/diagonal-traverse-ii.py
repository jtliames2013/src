class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        res=[]
        for i, row in enumerate(nums):
            for j, v in enumerate(row):
                if i+j>=len(res): res.append([])
                res[i+j].append(v)
                
        return [v for row in res for v in reversed(row)]


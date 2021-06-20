class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        mx=[float('-inf')]*3
        for t in triplets:
            if t[0]<=target[0] and t[1]<=target[1] and t[2]<=target[2]:
                mx[0]=max(mx[0], t[0])
                mx[1]=max(mx[1], t[1])
                mx[2]=max(mx[2], t[2])
        return mx==target


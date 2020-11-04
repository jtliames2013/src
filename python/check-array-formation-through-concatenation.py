class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        dic={p[0]: p for p in pieces}
        i, n=0, len(arr)
        while i<n:
            if arr[i] not in dic: return False
            j=0
            while j<len(dic[arr[i]]):
                if arr[i+j]!=dic[arr[i]][j]: return False
                j+=1
            i+=j
            
        return True


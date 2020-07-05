class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        mx, mn, n=max(arr), min(arr), len(arr)
        delta=(mx-mn)/(n-1)
        if delta==0: return True
        st=set(v-mn for v in arr)
        print(st)
        return len(st)==n and all(v%delta==0 for v in st)
        

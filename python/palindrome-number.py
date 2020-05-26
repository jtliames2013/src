class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0: return False
        base=1
        while base<=x: base*=10
        base//=10
        while x>0:
            if x//base != x%10: return False
            x%=base
            x//=10
            base//=100
        return True


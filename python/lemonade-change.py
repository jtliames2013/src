class Solution:
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        five=ten=0
        for b in bills:
            if b==5: five+=1
            elif b==10:
                five-=1
                ten+=1
            elif ten>0:
                five-=1
                ten-=1
            else:
                five-=3
            if five<0: return False
        return True

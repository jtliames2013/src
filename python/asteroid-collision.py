class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        stk=[]
        for a in asteroids:
            if a>0: 
                stk.append(a)
            else:
                while len(stk)!=0 and stk[-1]>0 and stk[-1]<-a: stk.pop()
                if len(stk)==0 or stk[-1]<0: stk.append(a)
                elif stk[-1]==-a: stk.pop()
                
        return stk


class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount<=0: return 0
        q1=[0]
        q2=[]
        visited=[True]+[False]*amount
        steps=1
        while q1:
            for i in q1:
                for c in coins:
                    n=i+c
                    if n==amount: return steps
                    elif n<amount:
                        if visited[n]==False: 
                            q2.append(n)
                            visited[n]=True
            q1, q2 = q2, []
            steps+=1
        return -1

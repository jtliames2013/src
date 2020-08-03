class Solution:
    def calculate(self, s: str) -> int:
        res, sign, n, i=0, 1, len(s), 0
        stk=[]
        while i<n:
            if s[i].isdigit():
                j=i
                num=0
                while j<n and s[j].isdigit(): 
                    num=num*10+ord(s[j])-ord('0')
                    j+=1
                res+=sign*num
                i=j
            elif s[i] in '+-':
                sign=1 if s[i]=='+' else -1
                i+=1
            elif s[i]=='(':
                stk.append([res, sign])
                res, sign=0, 1
                i+=1
            elif s[i]==')':
                t=stk.pop()
                res=t[0]+t[1]*res
                i+=1
            else:
                i+=1
                
        return res
            

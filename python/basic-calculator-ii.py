class Solution:
    def calculate(self, s: str) -> int:
        def isop(c):
            return c=='+' or c=='-' or c=='*' or c=='/'
        
        def process(num, op):
            if op=='+': nums.append(num)
            elif op=='-': nums.append(-num)
            else:
                t=nums.pop()
                nums.append(t*num if op=='*' else t//num+1 if t<0 and t%num!=0 else t//num)
            
        nums, i, n, op=[], 0, len(s), '+'
        while i<n:
            if s[i].isdigit():
                j=i
                num=0
                while j<n and s[j].isdigit():
                    num=num*10+ord(s[j])-ord('0')
                    j+=1
                i=j
                process(num, op)
            elif isop(s[i]):
                op=s[i]
                i+=1
            else:
                i+=1
                
        return sum(nums)


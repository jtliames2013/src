class Solution:
    def reformatNumber(self, number: str) -> str:
        number=number.replace(" ", "").replace("-", "")
        res=[]
        i, n=0, len(number)
        while n-i>4:
                res.append(number[i:i+3])
                i+=3
        if n-i<4:
            res.append(number[i:])
        elif n-i==4:
            res.append(number[i:i+2])
            res.append(number[i+2:])

        return '-'.join(res)


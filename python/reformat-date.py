class Solution:
    def reformatDate(self, date: str) -> str:
        months=["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        parts=date.split()
        y=int(parts[2])
        m=months.index(parts[1])+1
        d=int(parts[0][:-2])
        return '{:04d}-{:02d}-{:02d}'.format(y, m, d)


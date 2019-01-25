class Solution:
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        i, j=0, 0
        m, n=len(name), len(typed)
        while i<m and j<n:
            if name[i]!=typed[j]: return False
            i2=i+1
            while i2<m and name[i2]==name[i]: i2+=1
            j2=j+1
            while j2<n and typed[j2]==typed[j]:j2+=1
            if i2-i>j2-j: return False
            i=i2
            j=j2
            
        return i==m and j==n

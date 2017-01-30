class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        res = [''] * numRows
        index, step = 0, 1
        for ch in s:
            res[index] += ch
            if index == 0:
                step = 1
            elif index == numRows-1:
                step = -1
            index += step
        
        return ''.join(res)

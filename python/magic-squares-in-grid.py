class Solution:
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def isMagic(r, c):
            if grid[r][c]%2 != 0 or grid[r+1][c+1] != 5: return 0
            s="".join(str(grid[r+i//3][c+i%3]) for i in [0, 1, 2, 5, 8, 7, 6, 3])
            return s in "43816729" * 2 or s in "43816729"[::-1] * 2
        return sum(isMagic(i, j) for i in range(len(grid)-2) for j in range(len(grid[0])-2))

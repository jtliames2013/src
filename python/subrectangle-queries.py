class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.rec=rectangle
        self.update=[]

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.update.append([row1, col1, row2, col2, newValue])

    def getValue(self, row: int, col: int) -> int:
        for u in self.update[::-1]:
            if u[0]<=row<=u[2] and u[1]<=col<=u[3]:
                return u[4]
        return self.rec[row][col]


# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)


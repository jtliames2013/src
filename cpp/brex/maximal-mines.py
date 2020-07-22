给一个list的地雷，每个地雷包含3个数字，x，y坐标和爆炸范围，这三个数字都可以不是整数。
现在选其中一个地雷开始引爆，在每个地雷爆炸范围的地雷也会被引爆，爆炸这样就会传播开。
找到可以最终引爆最多地雷数的初始地雷。

import argparse
import collections
import csv
from datetime import datetime
import math
import os
import random
import sys

class App:
    def run(self):
        mines=[[0, 0, 1], [1, 0, 1], [3, 3, 0.5], [3, 3.5, 1], [4, 3.5, 1]]
        res=self.find_max_mines(mines)
        print(res)

    def find_max_mines(self, mines):
        def dist(i, j):
            return math.sqrt((i[0]-j[0])**2+(i[1]-j[1])**2)

        def dfs(i):
            visited[i]=True
            res=1
            for neighbor in graph[i]:
                if not visited[neighbor]: res+=dfs(neighbor)
            return res

        n=len(mines)
        if n==0:
            raise ValueError("Invalid args")

        graph=collections.defaultdict(set)
        for i in range(n):
            for j in range(i):
                x1, y1, r1=mines[i]
                x2, y2, r2=mines[j]
                if dist([x1, y1], [x2, y2])<=r1+r2:
                    graph[i].add(j)
                    graph[j].add(i)

        print(graph)
        maxNum, idx=0, -1
        visited=[False]*n
        for i in range(n):
            if not visited[i]:
                num=dfs(i)
                if maxNum<num:
                    maxNum=num
                    idx=i
        return idx

def run():
    App().run()

if __name__ == '__main__':
    run()


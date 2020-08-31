import argparse
import bisect
import collections
import csv
from datetime import datetime
import math
import os
import re
import random
import sys
import time

class App():
    def parsePassword1(self, in_file):
        res=[]
        with open(in_file, 'r') as fd:
            i, row, col, grid=0, 0, 0, []
            while True:
                line=fd.readline()
                if not line:
                    res.append(grid[len(grid)-row-1][col])
                    break

                line=line.rstrip()
                if not line:
                    res.append(grid[len(grid)-row-1][col])
                    i, row, col, grid=0, 0, 0, []
                else:
                    if i==0:
                        parts=line[1:-1].split(',')
                        row=int(parts[1].strip())
                        col=int(parts[0].strip())
                    else:
                        grid.append(list(line))
                    i+=1

        return ''.join(res)

    def parsePassword2(self, in_file):
        dic=collections.defaultdict(int)
        with open(in_file, 'r') as fd:
            i, index, row, col, grid=0, 0, 0, 0, []
            while True:
                line=fd.readline()
                if not line:
                    dic[index]=grid[len(grid)-row-1][col]
                    break

                line=line.rstrip()
                if not line:
                    dic[index]=grid[len(grid)-row-1][col]
                    i, index, row, col, grid=0, 0, 0, 0, []
                else:
                    if i==0:
                        index=int(line)
                    elif i==1:
                        parts=line[1:-1].split(',')
                        row=int(parts[1].strip())
                        col=int(parts[0].strip())
                    else:
                        grid.append(list(line))
                    i+=1

        res=['']*len(dic)
        for k, v in dic.items(): res[k]=v
        return ''.join(res)

    def parsePassword3(self, in_file):
        dic=collections.defaultdict(int)
        with open(in_file, 'r') as fd:
            i, index, row, col, grid=0, 0, 0, 0, []
            while True:
                line=fd.readline()
                if not line:
                    dic[index]=grid[len(grid)-row-1][col]
                    break

                line=line.rstrip()
                if not line:
                    dic[index]=grid[len(grid)-row-1][col]
                    i, index, row, col, grid=0, 0, 0, 0, []
                else:
                    if i==0:
                        index=int(line)
                        if index in dic: break
                    elif i==1:
                        parts=line[1:-1].split(',')
                        row=int(parts[1].strip())
                        col=int(parts[0].strip())
                    else:
                        grid.append(list(line))
                    i+=1

        res=['']*len(dic)
        for k, v in dic.items(): res[k]=v
        return ''.join(res)

class App2():
    def parsePassword1(self):
        res=[]
        i, row, col, grid=0, 0, 0, []
        for line in sys.stdin:
            line=line.rstrip()
            if line=='exit':
                res.append(grid[len(grid)-row-1][col])               
                break

            if not line:
                res.append(grid[len(grid)-row-1][col])
                i, row, col, grid=0, 0, 0, []
            else:
                if i==0:
                    parts=line[1:-1].split(',')
                    row=int(parts[1].strip())
                    col=int(parts[0].strip())
                else:
                    grid.append(list(line))
                i+=1

        print(''.join(res))

    def parsePassword2(self):
        dic=collections.defaultdict(int)
        i, index, row, col, grid=0, 0, 0, 0, []
        for line in sys.stdin:
            line=line.rstrip()
            if line=='exit':
                dic[index]=grid[len(grid)-row-1][col]
                break            

            if not line:
                dic[index]=grid[len(grid)-row-1][col]
                i, index, row, col, grid=0, 0, 0, 0, []
            else:
                if i==0:
                    index=int(line)
                elif i==1:
                    parts=line[1:-1].split(',')
                    row=int(parts[1].strip())
                    col=int(parts[0].strip())
                else:
                    grid.append(list(line))
                i+=1

        res=['']*len(dic)
        for k, v in dic.items(): res[k]=v
        print(''.join(res))

    def parsePassword3(self):
        dic=collections.defaultdict(int)
        i, index, row, col, grid=0, 0, 0, 0, []
        for line in sys.stdin:
            line=line.rstrip()
            if line=='exit':
                dic[index]=grid[len(grid)-row-1][col]
                break

            if not line:
                dic[index]=grid[len(grid)-row-1][col]
                i, index, row, col, grid=0, 0, 0, 0, []
            else:
                if i==0:
                    index=int(line)
                    if index in dic: break
                elif i==1:
                    parts=line[1:-1].split(',')
                    row=int(parts[1].strip())
                    col=int(parts[0].strip())
                else:
                    grid.append(list(line))
                i+=1

        res=['']*len(dic)
        for k, v in dic.items(): res[k]=v
        print(''.join(res))

def main():
    print(App().parsePassword1(sys.argv[1]))
    print(App().parsePassword2(sys.argv[2]))
    print(App().parsePassword3(sys.argv[3]))

    App2().parsePassword1()
    App2().parsePassword2()
    App2().parsePassword3()

if __name__ == '__main__':
    main()


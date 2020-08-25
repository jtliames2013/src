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

M=20
N=20

class Rectangle:
    def __init__(self, ul, br, ch):
        self.ul=ul
        self.br=br
        self.ch=ch

class Printer():
    def __init__(self):
        self.origin='*'
        self.canvas=[[self.origin for j in range(N)] for i in range(M)]
        self.rects=[]
        self.removed=[]

    def add_rect(self, rect):
        self.rects.append(rect)

    def move_to_top(self, pos):
        for k in range(len(self.rects)-1, -1, -1):
            if self.rects[k].ul[0]<=pos[0]<=self.rects[k].br[0] and self.rects[k].ul[1]<=pos[1]<=self.rects[k].br[1]:
                break
        
        if k==-1: return
        self.rects.append(self.rects.pop(k))

    def drag(self, start, end):
        for k in range(len(self.rects)-1, -1, -1):
            if self.rects[k].ul[0]<=start[0]<=self.rects[k].br[0] and self.rects[k].ul[1]<=start[1]<=self.rects[k].br[1]:
                break
        
        if k==-1: return

        delta=[end[0]-start[0], end[1]-start[1]]
        if delta[0]<-self.rects[k].ul[0]: delta[0]=-self.rects[k].ul[0]
        if delta[0]>M-self.rects[k].br[0]-1: delta[0]=M-self.rects[k].br[0]-1
        if delta[1]<-self.rects[k].ul[1]: delta[1]=-self.rects[k].ul[1]
        if delta[1]>N-self.rects[k].br[1]-1: delta[1]=N-self.rects[k].br[1]-1
        self.rects[k].ul[0]+=delta[0]
        self.rects[k].ul[1]+=delta[1]
        self.rects[k].br[0]+=delta[0]
        self.rects[k].br[1]+=delta[1]

    def delete(self, ul, br):
        self.removed.append(Rectangle(ul, br, self.origin))

    def print(self):
        for i in range(M):
            for j in range(N):
                ch, rem=self.canvas[i][j], False
                for k in range(len(self.removed)-1, -1, -1):
                    if self.removed[k].ul[0]<=i<=self.removed[k].br[0] and self.removed[k].ul[1]<=j<=self.removed[k].br[1]:
                        ch=self.removed[k].ch
                        rem=True
                        break
                
                if not rem:
                    for k in range(len(self.rects)-1, -1, -1):
                        if self.rects[k].ul[0]<=i<=self.rects[k].br[0] and self.rects[k].ul[1]<=j<=self.rects[k].br[1]:
                            ch=self.rects[k].ch
                            break

                print(ch+' ', end='') if j<N-1 else print(ch)

def main():
    printer=Printer()
    printer.add_rect(Rectangle([1, 1], [5, 5], 'A'))
    printer.add_rect(Rectangle([2, 2], [6, 6], 'B'))
    printer.add_rect(Rectangle([3, 3], [7, 7], 'C'))
    printer.print()
    print()

    printer.move_to_top([1,1])
    printer.print()
    print()

    printer.move_to_top([2,6])
    printer.print()
    print()

    printer.drag([2,2], [7, 7])
    printer.print()
    print()

    printer.drag([7,7], [18, 18])
    printer.print()
    print()

    printer.delete([3, 3], [5, 5])
    printer.print()
    print()

    printer.drag([15,15], [3, 3])
    printer.print()
    print()

if __name__ == '__main__':
    main()


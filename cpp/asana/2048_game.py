https://github.com/gabrielecirulli/2048

import argparse
import bisect
import collections
import copy
import csv
from datetime import datetime
import math
import os
import re
import random
import sys
import time

BOARD_SIZE=4
START_TILES=4

class Pos:
    def __init__(self, row, col):
        self.row=row
        self.col=col

class Tile:
    def __init__(self, row, col, val):
        self.row=row
        self.col=col
        self.value=val
        self.mergedFrom=False

    def update_position(self, pos):
        self.row=pos.row
        self.col=pos.col

class Board:
    def __init__(self):
        self.size=BOARD_SIZE
        self.start_tiles=START_TILES
        self.won=False
        self.over=False
        self.cells=[[None for col in range(self.size)] for row in range(self.size)]
        self.directions={'left': [0, -1], 'right': [0, 1], 'up': [-1, 0], 'down': [1, 0]}
        for _ in range(self.start_tiles):
            self.add_random_tile()

    def add_random_tile(self):
        pos=self.get_random_avail_cell()
        if pos:
            value=2 if random.randrange(100)<90 else 4
            tile=Tile(pos.row, pos.col, value)
            self.insert_tile(tile)

    def insert_tile(self, tile):
        self.cells[tile.row][tile.col]=tile

    def within_bound(self, pos):
        if pos.row<0 or pos.row>=self.size or pos.col<0 or pos.col>=self.size: return False
        else: return True

    def get_tile(self, pos):
        if not self.within_bound(pos): return None
        return self.cells[pos.row][pos.col]

    def get_random_avail_cell(self):
        avail=[]
        for row in range(self.size):
            for col in range(self.size):
                if not self.cells[row][col]:
                    avail.append(Pos(row, col))

        if len(avail)==0: return None
        return avail[random.randrange(len(avail))]

    def cells_avail(self):
        return self.get_random_avail_cell()!=None

    def has_match(self):
        for row in range(self.size):
            for col in range(self.size):
                tile=self.cells[row][col]
                if tile:
                    for d in self.directions.values():
                        pos=[row+d[0], col+d[1]]
                        neighbor=self.get_tile(pos)
                        if neighbor and neighbor.value==tile.value:
                            return True

        return False

    def find_first_avail_pos(self, pos, dir):
        prev=copy.deepcopy(pos)
        curr=copy.deepcopy(pos)
        curr.row, curr.col=curr.row+dir[0], curr.col+dir[1]
        while self.within_bound(curr) and not self.cells[curr.row][curr.col]:
            prev=copy.deepcopy(curr)
            curr.row, curr.col=curr.row+dir[0], curr.col+dir[1]
        return prev, curr

    def position_equal(self, pos, tile):
        return pos.row==tile.row and pos.col==tile.col

    def clear_merged(self):
        for row in range(self.size):
            for col in range(self.size):
                if self.cells[row][col]:
                    self.cells[row][col].mergedFrom=False

    def get_traversals(self, dir):
        traversals=[[i for i in range(self.size)], [i for i in range(self.size)]]
        if dir[1]==1: traversals[1]=traversals[1][::-1]
        if dir[0]==1: traversals[0]=traversals[0][::-1]

        return traversals

    def move(self, direction):
        moved=False
        self.clear_merged()
        dir=self.directions[direction]
        traversals=self.get_traversals(dir)
        for row in traversals[0]:
            for col in traversals[1]:
                pos=Pos(row, col)
                tile=self.get_tile(pos)
                if not tile: continue

                first_avail_pos, next=self.find_first_avail_pos(pos, dir)
                next_tile=self.get_tile(next)

                if next_tile and next_tile.value==tile.value and not next_tile.mergedFrom:
                    merged=Tile(next.row, next.col, tile.value*2)
                    merged.mergedFrom=True
                    self.cells[merged.row][merged.col]=merged
                    self.cells[tile.row][tile.col]=None
                    tile.update_position(next)

                    if merged.value==2048: self.won=True
                else:
                    self.cells[pos.row][pos.col]=None
                    self.cells[first_avail_pos.row][first_avail_pos.col]=tile
                    tile.update_position(first_avail_pos)

                if not self.position_equal(pos, tile):
                    moved=True

        if moved:
            self.add_random_tile()
            if not self.cells_avail and not self.has_match():
                self.over=True

    def game_over(self):
        return self.won or self.over

    def print(self):
        for i in range(self.size):
            for j in range(self.size):
                ch='{0: <5}'.format('*') if not self.cells[i][j] else '{0: <5}'.format(str(self.cells[i][j].value))
                print(ch+' ', end='') if j<self.size-1 else print(ch)

class Game:
    def __init__(self):
        self.board=Board()

    def run(self):
        self.board.print()

        for line in sys.stdin:
            line=line.rstrip()
            if line=='exit':
                break
            if line=='left' or line=='right' or line=='up' or line=='down':
                self.board.move(line)
            else:
                print('Invalid move!')
            self.board.print()

            if self.board.game_over():
                break

        print('Game over!')

def main():
    Game().run()

if __name__ == '__main__':
    main()


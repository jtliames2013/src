#-A -B -BB +C -C -CC =CCC

import argparse
import bisect
import collections
import csv
from datetime import datetime
import math
import os
import random
import sys
import time

class cardGame():
    def __init__(self):
        self.num_cards_in_hand=3
        self.dic={'+': 0, '-': 1, '=': 2, 'A': 0, 'B': 1, 'C': 2}

    def getCardsInHand(self, cards):
        def bitCount(n):
            res=0
            while n:
                res+=n&1
                n>>=1
            return res

        def isValidBitCount(output):
            # +/-/=
            mask=0
            for i in output:
                mask |= 1<<self.dic[cards[i][0]]
            cnt=bitCount(mask)
            if cnt!=1 and cnt!=self.num_cards_in_hand: return False

            # A/B/C
            mask=0
            for i in output:
                mask |= 1<<self.dic[cards[i][1]]
            cnt=bitCount(mask)
            if cnt!=1 and cnt!=self.num_cards_in_hand: return False

            # number of letters
            mask=0
            for i in output:
                mask |= 1<<(len(cards[i])-2)
            cnt=bitCount(mask)
            if cnt!=1 and cnt!=self.num_cards_in_hand: return False

            return True

        def isValid(output):
            # +/-/=
            mask=[0]*self.num_cards_in_hand
            for i in output:
                mask[self.dic[cards[i][0]]]=1
            cnt=mask.count(1)
            if cnt!=1 and cnt!=self.num_cards_in_hand: return False

            # A/B/C
            mask=[0]*self.num_cards_in_hand
            for i in output:
                mask[self.dic[cards[i][1]]]=1
            cnt=mask.count(1)
            if cnt!=1 and cnt!=self.num_cards_in_hand: return False

            # number of letters
            mask=[0]*self.num_cards_in_hand
            for i in output:
                mask[len(cards[i])-2]=1
            cnt=mask.count(1)
            if cnt!=1 and cnt!=self.num_cards_in_hand: return False

            return True

        def dfs(output, start, n, k):
            if k==0:
                if isValid(output): res.append([cards[i] for i in output])
                return

            for i in range(start, n-k+1):
                output.append(i)
                dfs(output, i+1, n, k-1)
                output.pop()

        res, output=[], []
        dfs(output, 0, len(cards), self.num_cards_in_hand)
        return res

def main():
    game=cardGame()
    for line in sys.stdin:
        line=line.rstrip()
        if line == 'exit':
            break
        print(game.getCardsInHand(line.split()))
    print("Exited...")

if __name__ == '__main__':
    main()



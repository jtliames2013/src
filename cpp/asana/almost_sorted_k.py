import argparse
import bisect
import collections
import copy
import csv
from datetime import datetime
import heapq
import math
import os
import re
import random
import sys
import time

class App:
    def almost_sorted_k(self, arr, k):
        n, i=len(arr), 0
        res, pq=[], []
        while i<k+1 and i<n:
            heapq.heappush(pq, arr[i])
            i+=1

        while i<n:
            res.append(heapq.heappop(pq))
            heapq.heappush(pq, arr[i])
            i+=1
            
        while pq:
            res.append(heapq.heappop(pq))

        return res

def main():
    app=App()
    print(app.almost_sorted_k([6, 5], 3))
    print(app.almost_sorted_k([6, 5, 3, 2, 8, 10, 9], 3))
    print(app.almost_sorted_k([10, 9, 8, 7, 4, 70, 60, 50], 4))

if __name__ == '__main__':
    main()


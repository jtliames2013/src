import argparse
import bisect
import collections
import copy
import csv
from datetime import datetime
import heapq
import json
import math
import os
import re
import random
import sys
import time

class Data:
    def __init__(self):
        self.mn=float('inf')
        self.mx=float('-inf')
        self.sum=0
        self.cnt=0

class App:
    def stats(self, args):
        data_by_day=collections.defaultdict(lambda: collections.defaultdict(Data))
        data_by_time=collections.defaultdict(set)
        for filename in os.listdir(args.in_dir):
            with open(os.path.join(args.in_dir, filename), 'r') as fd:
                content=csv.reader(fd, delimiter=',')
                for row in content:
                    if len(row)!=3: continue # validate format
                    if row[0]=="sensor_id": continue # validate format
                    if row[2] in data_by_time[row[0]]: continue # duplicate

                    date=datetime.fromtimestamp(int(row[2])).strftime('%Y-%m-%d')
                    val=float(row[1])
                    data_by_day[row[0]][date].mn=min(data_by_day[row[0]][date].mn, val)
                    data_by_day[row[0]][date].mx=max(data_by_day[row[0]][date].mx, val)
                    data_by_day[row[0]][date].sum+=val
                    data_by_day[row[0]][date].cnt+=1
                    data_by_time[row[0]].add(row[2])

        print(json.dumps(data_by_day, default=lambda x: x.__dict__))
        for sensor, v in data_by_day.items():
            for date, data in v.items():
                print('{0} {1} {2:.2f} {3:.2f} {4:.2f} {5}'.format(sensor, date, data.mn, data.mx, data.sum/data.cnt, data.cnt))

def parse():
    parser=argparse.ArgumentParser()
    parser.add_argument("--in-dir")

    return parser.parse_args()

def main():
    args=parse()
    App().stats(args)

if __name__ == '__main__':
    main()


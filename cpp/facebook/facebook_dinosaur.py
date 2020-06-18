import argparse
import collections
import csv
from datetime import datetime
import os
import random
import sys

MAX_ID = 100

class App:
    def __init__(self):
        self.id=random.randrange(0, MAX_ID)

    def run(self, args):
        print(self.id)
        self.sortLog(args.csv_file_1, args.csv_file_2, args.out_csv_file)

    def sortLog(self, file1, file2, outfile):
        d=collections.defaultdict()
        with open(file2) as cf2:
            content = csv.reader(cf2, delimiter=',')
            for row in content:
                if row[2] == "two legs":
                    d[row[0]] = int(row[1])

        res=[]
        with open(file1) as cf1:
            content = csv.reader(cf1, delimiter=',')
            for row in content:
                if row[0] in d:
                    res.append([row[0], int(row[1])*d[row[0]]])

        res.sort(reverse=True, key=lambda r: r[1])
        print(res)

        with open(outfile, 'w') as outfd:
            for i in res:
                outfd.write(i[0]+"\n")

def parse():
    parser = argparse.ArgumentParser()
    parser.add_argument('--csv-file-1')
    parser.add_argument('--csv-file-2')
    parser.add_argument('--out-csv-file')

    args = parser.parse_args()
    return args

def run():
    args=parse()
    App().run(args)

if __name__ == '__main__':
    run()

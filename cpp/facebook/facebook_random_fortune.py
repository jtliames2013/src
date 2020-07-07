一个文件里有一些fortune sentence，delimiter是一行‘#’， eg
abc
#
abc，
def
#
随机输出一个fortune sentence，如果是多行，合并为一行。 附加：如果file很大如何处理

import argparse
import collections
import csv
from datetime import datetime
import math
import os
import random
import sys

MAX_ID = 100

class App:
    def __init__(self):
        self.id=random.randrange(0, MAX_ID)

    def run(self, args):
        print(self.id)
        res=self.randomFortune(args.input_file)
        print(res)

    def randomFortune(self, file):
        res, s=[], ""
        with open(file, 'r') as fd:
            while True:
                line=fd.readline()
                if not line: break
                line=line.rstrip()
                if line=="#":
                    if s: res.append(s)
                    s=""
                else:
                    s+=line
            if s: res.append(s)

        return res[random.randrange(0, len(res))]

def parse():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input-file')
    args = parser.parse_args()
    return args

def run():
    args=parse()
    App().run(args)

if __name__ == '__main__':
    run()


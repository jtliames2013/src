import argparse
from datetime import datetime
import os
import random
import sys

MAX_ID = 100
CHUNK_SIZE = 6

class App:
    def __init__(self):
        self.id=random.randrange(0, MAX_ID)

    def run(self, args):
        print(self.id)
        self.mergeLog(args.log_file_1, args.log_file_2, args.out_log_file)

    def mergeLog(self, file1, file2, outfile):
        def lessthan(line1, line2):
            part1=line1.split(' ')
            part2=line2.split(' ')
            t1=part1[0]+" "+part1[1]+" "+part1[2]
            t2=part2[0]+" "+part2[1]+" "+part2[2]
            # syslog timestamp
            d1=datetime.strptime(t1, "%b %d %H:%M:%S")
            d2=datetime.strptime(t2, "%b %d %H:%M:%S")
            return d1<d2

        res = []
        with open(file1, 'r') as fd1, open(file2, 'r') as fd2:
            line1=fd1.readline()
            line2=fd2.readline()
            while line1 or line2:
                if not line1: 
                    res.append(line2)
                    line2=fd2.readline()
                elif not line2: 
                    res.append(line1)
                    line1=fd1.readline()
                else:
                    if lessthan(line1, line2):
                        res.append(line1)
                        line1=fd1.readline()
                    else:
                        res.append(line2)
                        line2=fd2.readline()

                if len(res) == CHUNK_SIZE:
                    with open(outfile, 'a') as outfd:
                        outfd.writelines(res)
                    res = []

            if len(res) > 0:
                with open(outfile, 'a') as outfd:
                    outfd.writelines(res)

def parse():
    parser = argparse.ArgumentParser()
    parser.add_argument('--log-file-1')
    parser.add_argument('--log-file-2')
    parser.add_argument('--out-log-file')

    args = parser.parse_args()
    return args

def run():
    args=parse()
    App().run(args)

if __name__ == '__main__':
    run()

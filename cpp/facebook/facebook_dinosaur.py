/*
dinosaurs question

You will be supplied with two data files in CSV format. The first file contains
statistics about various dinosaurs. The second file contains additional data.

Given the following formula,

speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)
Where g = 9.8 m/s^2 (gravitational constant)
(normal code)
Write a program to read in the data files from disk, it must then print the names
of only the bipedal dinosaurs from fastest to slowest. Do not print any other information.

$ cat dataset1.csv
NAME,LEG_LENGTH,DIET
Hadrosaurus,1.2,herbivore
Struthiomimus,0.92,omnivore
Velociraptor,1.0,carnivore
Triceratops,0.87,herbivore
Euoplocephalus,1.6,herbivore
Stegosaurus,1.40,herbivore
Tyrannosaurus Rex,2.5,carnivore

$ cat dataset2.csv
NAME,STRIDE_LENGTH,STANCE
Euoplocephalus,1.87,quadrupedal
Stegosaurus,1.90,quadrupedal
Tyrannosaurus Rex,5.76,bipedal
Hadrosaurus,1.4,bipedal
Deinonychus,1.21,bipedal
Struthiomimus,1.34,bipedal
Velociraptor,2.72,bipedal
*/

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
        self.sortDinosaur(args.csv_file_1, args.csv_file_2, args.out_csv_file)

    def sortDinosaur(self, file1, file2, outfile):
        d=collections.defaultdict()
        with open(file2, 'r') as fd2:
            content=csv.reader(fd2, delimiter=',')
            i=0
            for i, row in enumerate(content):
                if i==0: continue # skip header
                if row[2]=="bipedal":
                    d[row[0]]=float(row[1])

        res=[]
        with open(file1, 'r') as fd1:
            content=csv.reader(fd1, delimiter=',')
            i=0
            for i, row in enumerate(content):
                if i==0: continue # skip header
                if row[0] in d:
                    res.append([row[0], (d[row[0]]/float(row[1])-1)*math.sqrt(float(row[1])*9.8)])
        res.sort(reverse=True, key=lambda v: v[1])

        with open(outfile, 'w') as outd:
            for v in res:
                outd.write(v[0]+'\n')

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


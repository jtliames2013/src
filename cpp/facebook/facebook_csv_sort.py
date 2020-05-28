import csv
import fileinput
import glob
import os
import re
import sys

def parse_and_sort(file1, file2):
    with open(file1) as csvfile:
        content=csv.reader(csvfile, delimiter=',')
        rows=list(content)        
        rows.sort(key=lambda row: row[0])
        print(rows)

def find_and_replace(filename):
    # with open(filename, 'r') as fd:
    #     for line in fd:
    #         emails = re.findall("([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)", line)
    #         print(emails)

    # with fileinput.FileInput(filename, inplace=True) as file:
    #     for line in file:
    #         print(line.replace("a@foo.com", "old@foo.com"), end='')

    with open(filename, 'r') as fd:
        data=fd.read()
    
    emails = re.findall("([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)", data)
    for email in emails:
        data=data.replace(email, "remove@foo.com")

    with open(filename, 'w') as fd:
        fd.write(data)

def search_and_change(directory):
    # for file in os.listdir(directory):
    #     if file.endswith(".cpp"):
    #         print(os.path.join(directory, file))

    # for file in glob.glob(os.path.join(directory, "**/*.txt"), recursive=True):
    #     print(os.path.join(directory, file))

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".txt"):
                fullname=os.path.join(root, file)
                print(fullname)
                find_and_replace(fullname)

if __name__ == "__main__":
    file1=sys.argv[1]
    file2=sys.argv[2]
    directory=sys.argv[3]
    parse_and_sort(file1, file2)
    search_and_change(directory)

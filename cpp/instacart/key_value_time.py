import argparse
import bisect
import collections
import csv
from datetime import datetime
from multipledispatch import dispatch 
import math
import os
import random
import sys
import time

class KVStore:
    def __init__(self):
        self.dic=collections.defaultdict(str)

    def set(self, key, val):
        self.dic[key]=val

    def get(self, key):
        return self.dic.get(key, None)

class KVStore2:
    def __init__(self):
        self.dic_time=collections.defaultdict(dict)
        self.dic_latest=collections.defaultdict(str)

    def set(self, key, val):
        curr_time=int(time.time()*1000)
        self.dic_time[key][curr_time]=val
        self.dic_latest[key]=val
        return curr_time

    @dispatch(str)
    def get(self, key):
        return self.dic_latest.get(key, None)

    @dispatch(str, int)
    def get(self, key, timestamp):
        if key not in self.dic_time: return None
        return self.dic_time[key].get(timestamp, None)

class KVStore3:
    def __init__(self):
        self.dic_val=collections.defaultdict(list)
        self.dic_time=collections.defaultdict(list)

    def set(self, key, val):
        curr_time=int(time.time()*1000)
        self.dic_val[key].append(val)
        self.dic_time[key].append(curr_time)
        return curr_time

    @dispatch(str)
    def get(self, key):
        if key not in self.dic_val or len(self.dic_val[key])==0: return None
        return self.dic_val[key][-1]

    @dispatch(str, float)
    def get(self, key, timestamp):
        if key not in self.dic_time or len(self.dic_time[key])==0: return None
        i=bisect.bisect(self.dic_time[key], timestamp)
        if i==0: return None
        return self.dic_val[key][i-1]

def main():
    print('#1')
    kv=KVStore()
    kv.set('foo', 'bar')
    print(kv.get('foo'))
    kv.set('foo', 'bar2')
    print(kv.get('foo'))
    print(kv.get('foo2'))

    print('#2')
    kv2=KVStore2()
    timestamp=kv2.set('foo', 'bar')
    time.sleep(1)
    kv2.set('foo', 'bar2')
    print(kv2.get('foo'))
    print(kv2.get('foo', timestamp))

    print('#3')
    kv3=KVStore3()
    timestamp=kv3.set('foo', 'bar')
    time.sleep(1)
    kv3.set('foo', 'bar2')
    print(kv3.get('foo'))
    print(kv3.get('foo', timestamp+0.75))

if __name__ == '__main__':
    main()


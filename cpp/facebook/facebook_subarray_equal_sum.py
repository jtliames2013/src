给一个数组，均为正整数。将该数组分成连续的两部分，使得两部分的和相等。求分开的元素位置下标。假设有且只有唯一的答案。
比如：[1,2,3]，返回1. 因为sum([1,2])=sum([3])

class App:
    def __init__(self):
        self.id=random.randrange(0, MAX_ID)

    def run(self, args):
        print(self.id)
        arr=[1, 2, 3, 3, 3]
        res1=self.subarry_equal_sum1(arr)
        print(res1)
        res2=self.subarry_equal_sum2(arr)
        print(res2)

    def subarry_equal_sum1(self, arr):
        s=sum(arr)
        if s%2!=0: return -1
        s//=2
        total=0
        for i, v in enumerate(arr):
            total+=v
            if total==s: return i
        return -1

    def subarry_equal_sum2(self, arr):
        l, r, lsum, rsum=0, len(arr)-1, 0, 0
        while l<=r:
            if lsum<rsum:
                lsum+=arr[l]
                l+=1
            else:
                rsum+=arr[r]
                r-=1
        return l-1 if lsum==rsum else -1

def parse():
    parser = argparse.ArgumentParser()

    args = parser.parse_args()
    return args

def run():
    args=parse()
    App().run(args)

if __name__ == '__main__':
    run()



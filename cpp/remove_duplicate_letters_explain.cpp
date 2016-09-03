方法一

用栈。

首先对字符串出现的个数进行统计。

然后对字符串扫描，每遇到一个字符串，判断其是否在栈中，如果在则跳过。（计数 – 1）

如果不在栈中，和栈顶的元素判断，要是当前栈顶的元素比较大而且cnt不为0（也就是说之后还有这个元素），就把栈顶弹出。然后把当前的元素入栈。

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        vis, cnt = [False] * 26, [0] * 26
        ans = []
        for c in s:
            cnt[ord(c) - 97] += 1  # ord(a) =97
        for c in s:
            index = ord(c) - 97
            cnt[index] -= 1
            if vis[index]: continue
            while ans and ans[-1] > c and cnt[ord(ans[-1]) - 97]:
                vis[ord(ans.pop()) - 97] = False
            ans.append(c)
            vis[index] = True

        return ''.join(ans)

方法二

和这个差不多https://leetcode.com/discuss/73777/easy-to-understand-iterative-java-solution

找每个字符出现的最后的位置， 取其中最小的作为end。（这个元素必须在end或者end以前出现，否则就没了= =）

从start（一开始设为0）枚举到end，最小的那个作为当前的字符。如此循环。

如：dcbacdcd

最后出现的位置：a:3 , b: 2, c : 6, d: 7

于是0~2中最小的元素为b

接着3~3 为a

接着 4~6 为c

接着 7~7 为d

所以为bacd

class Solution(object):
    def removeDuplicateLetters(self, s):
        if not s: return ''
        last_pos = collections.defaultdict(int)
        dic = set(s)
        for i, c in enumerate(s):
            last_pos[c] = i
 
        last_pos = collections.OrderedDict(sorted(last_pos.items(), key=lambda x: x[1]))
        start, end = 0, last_pos.items()[0][1]
        ans = []
        for i in xrange(len(last_pos)):
            min_c = 'z'
            for k in xrange(start, end + 1):
                if min_c > s[k] and s[k] in last_pos:
                    min_c = s[k]
                    start = k + 1
            ans += [min_c]
 
            del last_pos[min_c]
            if not last_pos:  break
            end = last_pos.items()[0][1]
 
        return ''.join(ans)


每次对每个字母出现的次数进行统计 cnt

然后扫描数组，找最小的字符min_c，并对于经过的每一个元素 cnt – 1 ，直到数组扫描完毕或者遇到cnt = 0的（cnt = 0说明后面没有这个元素了，不能继续，否则就丢掉了这个元素）

然后把字符串s中 min_c 替换成空 如此循环。

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = ''
        while s:
            cnt = collections.Counter(s)
            min_c, index = s[0], 0
            for i, c in enumerate(s):
                if min_c > c:
                    min_c, index = c, i
                cnt[c] -= 1
                if not cnt[c]: break
            ans += min_c
            s = s[index + 1:].replace(min_c,'')
        return ans


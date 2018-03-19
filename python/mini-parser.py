# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        stk=[]
        stk.append(NestedInteger())
        i=0
        while i<len(s):
            if s[i].isdigit() or s[i]=='-':
                j=i
                while j<len(s) and (s[j].isdigit() or s[j]=='-'): j+=1
                stk[-1].add(NestedInteger(int(s[i:j])))
                i=j
            elif s[i]=='[':
                stk.append(NestedInteger())
                i+=1
            elif s[i]==']':
                n=stk.pop()
                stk[-1].add(n)
                i+=1
            elif s[i]==',':
                i+=1
                
        return stk[0].getList()[0]

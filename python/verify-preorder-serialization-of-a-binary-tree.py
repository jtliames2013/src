class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        stk=[]
        preorder=preorder.split(',')
        for p in preorder:
            if p=="#":
                while len(stk)>0 and stk[-1]=="#":
                    stk.pop()
                    if len(stk)==0: return False
                    stk.pop()
            stk.append(p)
            
        if len(stk)==1 and stk[-1]=="#": return True
        else: return False

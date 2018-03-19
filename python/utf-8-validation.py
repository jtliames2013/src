1.
class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        i=0
        count=0
        while i<len(data):
            if count==0:
                if (data[i]>>7) == 0: count=0
                elif (data[i]>>5) == 0b110: count=1
                elif (data[i]>>4) == 0b1110: count=2
                elif (data[i]>>3) == 0b11110: count=3
                else: return False                
            else:
                if (data[i]>>6) != 0b10: return False
                count-=1
            i+=1
            
        return count==0

2.
class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        i=0
        count=0
        while i<len(data):
            if (data[i]>>7) == 0: count=0
            elif (data[i]>>5) == 0b110: count=1
            elif (data[i]>>4) == 0b1110: count=2
            elif (data[i]>>3) == 0b11110: count=3
            else: return False
            
            i+=1
            if i+count>len(data): return False
            j=i
            while j<i+count:
                if (data[j]>>6) != 0b10: return False
                j+=1
            i=j
            
        return True


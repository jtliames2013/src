class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        zeros, ones, n=0, 0, len(binary)
        for c in binary:
            if c=='0': zeros+=1
            elif zeros==0: ones+=1
        if ones==n: return binary
        return (ones+zeros-1)*'1' + '0' + (n-ones-zeros)*'1'


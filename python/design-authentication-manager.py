class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.timeToLive=timeToLive
        self.dic=collections.defaultdict(int)

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.dic[tokenId]=currentTime

    def renew(self, tokenId: str, currentTime: int) -> None:
        if tokenId in self.dic and currentTime-self.dic[tokenId]<self.timeToLive:
            self.dic[tokenId]=currentTime

    def countUnexpiredTokens(self, currentTime: int) -> int:
        return sum([currentTime-v<self.timeToLive for k, v in self.dic.items() ])


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)


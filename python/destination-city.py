class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        src, des=map(set, zip(*paths))
        return next(iter(des-src))


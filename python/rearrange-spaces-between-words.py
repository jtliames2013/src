class Solution:
    def reorderSpaces(self, text: str) -> str:
        words=text.split()
        n, m=len(text), len(words)
        spaces=n-sum(len(w) for w in words)
        div=spaces//(m-1) if m>1 else 0
        mod=spaces%(m-1) if m>1 else spaces
        return (' '*div).join(words)+' '*mod


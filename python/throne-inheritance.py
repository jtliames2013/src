class ThroneInheritance:

    def __init__(self, kingName: str):
        self.root=kingName
        self.graph=collections.defaultdict(list)
        self.dead=set()

    def birth(self, parentName: str, childName: str) -> None:
        self.graph[parentName].append(childName)

    def death(self, name: str) -> None:
        self.dead.add(name)

    def getInheritanceOrder(self) -> List[str]:
        def dfs(node):
            if node not in self.dead:
                res.append(node)
            for child in self.graph[node]:
                dfs(child)
            
        res=[]
        dfs(self.root)
        return res


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()

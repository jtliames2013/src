class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph=[[] for i in range(numCourses)]
        incomingCnt=[0]*numCourses
        for i, j in prerequisites:
            if i not in graph[j]:
                graph[j].append(i)
                incomingCnt[i]+=1
                
        st=[i for i in range(numCourses) if incomingCnt[i]==0]
        while st:
            f=st.pop(0)
            for neighbor in graph[f]:
                incomingCnt[neighbor]-=1
                if incomingCnt[neighbor]==0:
                    st.append(neighbor)
                    
        for i in range(numCourses):
            if incomingCnt[i]>0: return False
        return True


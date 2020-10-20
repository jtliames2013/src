class Solution:
    def hasPath(self, maze, start, destination):
        def bfs():
            q=[start]
            maze[start[0]][start[1]]=2

            while q:
                f=q.pop(0)
                for k in delta:
                    np=[f[0], f[1]]
                    while 0<=np[0]<m and 0<=np[1]<n and maze[np[0]][np[1]]!=1:
                        np[0]+=k[0]
                        np[1]+=k[1]
                    np[0]-=1
                    np[1]-=1
                    if maze[np[0]][np[1]]!=0: continue
                    if np==destination: return True
                    maze[np[0]][np[1]]=2
                    q.append(np)

            return False

        m, n=len(maze), len(maze[0])
        delta=[[-1, 0], [1, 0], [0, -1], [0, 1]]
        return bfs()


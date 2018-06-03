class Solution:
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        def dfs(r):
            for k in rooms[r]:
                if k not in st:
                    st.add(k)
                    dfs(k)
                    
        st=set([0])
        dfs(0)
        return len(st)==len(rooms)

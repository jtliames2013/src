class Solution:
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        bottom, left, top, right=float('inf'), float('inf'), float('-inf'), float('-inf')
        area=0
        st=set()
        
        for rect in rectangles:
            bottom=min(bottom, rect[0])
            left=min(left, rect[1])
            top=max(top, rect[2])
            right=max(right, rect[3])
            area+=(rect[2]-rect[0])*(rect[3]-rect[1])
            
            p1=(rect[0], rect[1])
            p2=(rect[0], rect[3])
            p3=(rect[2], rect[1])
            p4=(rect[2], rect[3])
            
            if p1 in st: st.remove(p1)
            else: st.add(p1)
            if p2 in st: st.remove(p2)
            else: st.add(p2)
            if p3 in st: st.remove(p3)
            else: st.add(p3)
            if p4 in st: st.remove(p4)
            else: st.add(p4)
        
        if (bottom, left) not in st or \
            (bottom, right) not in st or \
            (top, left) not in st or \
            (top, right) not in st or \
            len(st)!=4:
            return False
        
        return area==(top-bottom)*(right-left)

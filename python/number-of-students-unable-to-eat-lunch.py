class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count=collections.Counter(students)
        i, n=0, len(sandwiches)
        while i<n:
            if count[sandwiches[i]]==0: break
            count[sandwiches[i]]-=1
            i+=1
        return n-i


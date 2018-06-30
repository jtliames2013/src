855. Exam Room
DescriptionHintsSubmissionsDiscussSolution
In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

 

Example 1:

Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
​​​​​​​

Note:

1 <= N <= 10^9
ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.

class ExamRoom {
public:
    ExamRoom(int N) {
        size=N;
    }
    
    int seat() {
        if (s.empty()) {
            s.push_front(0);
            return 0;
        }
        int d=max(*s.begin(), size-1-*s.rbegin());
        auto curr=s.begin(), next=s.begin();
        for (++next; next!=s.end(); ++curr, ++next) {            
            d=max(d, (*next-*curr)/2);
        }

        if (d==*s.begin()) {
            s.push_front(0);            
            return 0;
        }
        curr=s.begin(), next=s.begin();
        for (++next; next!=s.end(); ++curr, ++next) {
            if (d==(*next-*curr)/2) {
                int p=(*curr+*next)/2;
                s.insert(next, p);                
                return p;
            }
        }
        s.push_back(size-1);
        return size-1;
    }
    
    void leave(int p) {
        for (auto iter=s.begin(); iter!=s.end(); ++iter) {
            if (*iter==p) {
                s.erase(iter);            
                break;
            }
        }
    }
private:
    int size;
    list<int> s;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

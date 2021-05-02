class SeatManager:

    def __init__(self, n: int):
        self.pq=[i for i in range(1, n+1)]

    def reserve(self) -> int:
        return heappop(self.pq)        

    def unreserve(self, seatNumber: int) -> None:
        heappush(self.pq, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)


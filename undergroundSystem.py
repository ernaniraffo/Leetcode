class UndergroundSystem:

    def __init__(self):
        self.check_in = {}
        self.time = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_in[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, time = self.check_in.pop(id)
        total = t - time
        if (startStation, stationName) not in self.time:
            self.time[(startStation, stationName)] = [total]
        else:
            self.time[(startStation, stationName)].append(total)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        times = self.time[(startStation, endStation)]
        return sum(times) / len(times)        


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)

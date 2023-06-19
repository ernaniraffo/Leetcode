class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curr_altitude = 0
        highest = 0
        for g in gain:
            curr_altitude += g
            if curr_altitude > highest:
                highest = curr_altitude
        return highest

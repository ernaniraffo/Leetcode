class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) == 2:
            return True
        a = getVector(coordinates[0], coordinates[1])
        for i in range(1, len(coordinates)-1):
            b = getVector(coordinates[i], coordinates[i + 1])
            if cross(a, b) != 0:
                return False
        return True
        
def cross(a, b):
    return a[0] * b[1] - a[1] * b[0]

def getVector(a, b):
    return [b[0] - a[0], b[1] - a[1]]


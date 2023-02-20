def isHappy(n):
    """
    :type n: int
    :rtype: bool
    """
    happy_dict = {}
    while True:
        s = str(n)
        if s in happy_dict:
            return False
        sum = 0
        for i in s:
            sum += int(i) * int(i)
        if sum == 1:
            return True
        happy_dict[s] = sum
        n = sum
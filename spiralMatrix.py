def spiralOrder(matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        n = len(matrix[0])

        dir_r = [0, 1, 0, -1]
        dir_c = [1, 0, -1, 0]
        direction = 0

        r = 0
        c = 0

        newMatrix = []
        seen = [[False for i in range(n)] for j in range(m)]
        
        while (len(newMatrix) != m*n):
            if (r >= 0 and r < m and c >= 0 and c < n and not seen[r][c]):
                newMatrix.append(matrix[r][c])
                seen[r][c] = True
            else:
                r -= dir_r[direction]
                c -= dir_c[direction]
                direction = (direction + 1) % 4
            r += dir_r[direction]
            c += dir_c[direction]
        
        return newMatrix
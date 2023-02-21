def findBall(grid: List[List[int]]) -> List[int]:
        answer = []
        num_rows = len(grid)
        num_cols = len(grid[0])
        
        for ball in range(num_cols):
            col = ball
            row = 0
            stuck = False

            while not stuck and row < num_rows:
                if grid[row][col] > 0 and col + 1 < num_cols and grid[row][col + 1] == grid[row][col]:
                        col += 1
                elif grid[row][col] < 0 and col - 1 >= 0 and grid[row][col - 1] == grid[row][col]:
                        col -= 1
                else:
                    stuck = True
                row += 1

            answer.append(col if not stuck else -1)
        
        return answer
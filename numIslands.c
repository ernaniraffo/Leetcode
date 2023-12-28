void dfs(char** grid, int r, int c, int m, int n) {
    if (grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '0';
    
    if (c + 1 < n) dfs(grid, r, c + 1, m, n);
    if (c - 1 >= 0) dfs(grid, r, c - 1, m, n);
    if (r + 1 < m) dfs(grid, r + 1, c, m, n);
    if (r - 1 >= 0) dfs(grid, r - 1, c, m, n);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int islands = 0;
    for (int r = 0; r < m; r += 1) {
        for (int c = 0; c < n; c += 1) {
            if (grid[r][c] == '1') {
                islands += 1;
                dfs(grid, r, c, m, n);
            }
        }
    }
    return islands;
}

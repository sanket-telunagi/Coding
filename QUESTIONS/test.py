from typing import List, Tuple

def dfs(grid: List[List[int]], visited: List[List[bool]], x: int, y: int, end: Tuple[int, int]) -> int:
    # Mark the current square as visited
    visited[x][y] = True

    # Check if we have reached the ending square
    if (x, y) == end:
        # Check if we have visited all non-obstacle squares
        all_visited = True
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != -1 and not visited[i][j]:
                    all_visited = False
                    break
            if not all_visited:
                break
        if all_visited:
            # Return 1 for a valid path
            return 1
        else:
            # Return 0 for an invalid path
            return 0

    # Helper function to check if a given position is within the grid and is not an obstacle
    def is_valid(x: int, y: int) -> bool:
        return x >= 0 and x < len(grid) and y >= 0 and y < len(grid[0]) and grid[x][y] != -1 and not visited[x][y]

    # Try moving to the adjacent squares
    count = 0
    if is_valid(x - 1, y):
        count += dfs(grid, visited, x - 1, y, end)
    if is_valid(x + 1, y):
        count += dfs(grid, visited, x + 1, y, end)
    if is_valid(x, y - 1):
        count += dfs(grid, visited, x, y - 1, end)
    if is_valid(x, y + 1):
        count += dfs(grid, visited, x, y + 1, end)

    # Mark the current square as not visited
    visited[x][y] = False
    print(count)
    return count

def main():
    # Initialize the grid
    # grid = [[1, 0, 0, 0],
    #         [0, 0, 0, 2],
    #         [0, -1, 0, 0]]

    grid = [[1,0,0,0],[0, 0 , 0 , 0],[0,0,0,2]]

    # Initialize the visited matrix
    visited = [[False] * len(grid[0]) for _ in range(len(grid))]

    # Find the starting and ending squares
   
    for i in range(0, len(grid)) :
        for j in range(0, len(grid[0])) :
            if grid[i][j] == 1 :
                start_x = i
                start_y = j
            if grid[i][j] == 2 :
                end = (i,j)

    count = dfs(grid,visited,start_x, start_y,end)
    print(count)

main()

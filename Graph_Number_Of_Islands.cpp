class Solution
{
public:
    bool issafe(int r, int c, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != '1')
        {
            return false;
        }
        return true;
    }

    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        if (visited[r][c])
        {
            return;
        }
        visited[r][c] = true;
        for (int delrow = -1; delrow <= 1; delrow++)
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int row = r + delrow;
                int col = c + delcol;
                if (issafe(row, col, grid))
                {
                    dfs(row, col, visited, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, visited, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
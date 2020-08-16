class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();

        for (int rowIndex = 0; rowIndex < row; ++ rowIndex)
        {
            for (int columnIndex = 0; columnIndex < column; ++ columnIndex)
            {
                if (0 == rowIndex && 0 == columnIndex)
                continue;
                if (0 == rowIndex)
                    grid[rowIndex][columnIndex] = grid[rowIndex][columnIndex - 1] + grid[rowIndex][columnIndex];
                if (0 == columnIndex)
                    grid[rowIndex][columnIndex] = grid[rowIndex - 1][columnIndex] + grid[rowIndex][columnIndex];
                if (0 != rowIndex && 0 != columnIndex)
                    grid[rowIndex][columnIndex] = min(grid[rowIndex][columnIndex - 1], grid[rowIndex - 1][columnIndex]) + grid[rowIndex][columnIndex];
            }
        }

        return grid[row - 1][column - 1];
    }
};
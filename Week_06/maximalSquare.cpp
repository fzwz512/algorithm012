class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        // 先保证非空集合
        if (row == 0) 
        {
            return 0;
        }
        int column = matrix[0].size();
        if (column == 0) 
        {
            return 0;
        }
        // dp 最关键的部分 转换思路 dp作为最大边长 而不是最大正方形面积
        int maxsize = 0;
        vector<vector<int>> dp(row, vector<int>(column));
        for (int rowIndex = 0; rowIndex < row; ++ rowIndex)
        {
            for (int columnIndex = 0; columnIndex < column; ++ columnIndex)
            {
                if ('1' == matrix[rowIndex][columnIndex])
                {
                    if (0 == rowIndex | 0 == columnIndex)
                        dp[rowIndex][columnIndex] = 1;
                    else
                        dp[rowIndex][columnIndex] = min(min(dp[rowIndex - 1][columnIndex], dp[rowIndex][columnIndex - 1]), dp[rowIndex - 1][columnIndex - 1]) + 1;
                    maxsize = max(maxsize, dp[rowIndex][columnIndex]);    
                }
            }
        }
        return maxsize * maxsize;

    }
};
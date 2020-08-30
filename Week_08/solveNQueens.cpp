class Solution {
public:
    static const int M = 20;
    int row[M], col[M], dg[M], udg[M];
    vector<string> a;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        a.resize(n, string(n, '.'));
        dfs(0, n);
        return res;    
    }

    void dfs(int u, int n) {
        if (u == n) {
            res.push_back(a);
        }
        for (int i = 0; i < n; i ++) {
            if (!row[i] && !col[i] && !dg[u - i + n] && !udg[i + u]) {
                a[u][i] = 'Q';
                row[i] = col[i] = dg[u - i + n] = udg[i + u] = 1;
                dfs(u + 1, n);
                a[u][i] = '.';
                row[i] = col[i] = dg[u - i + n] = udg[i + u] = 0;
            }
        }
    }
};
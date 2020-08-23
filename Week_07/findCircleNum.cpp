class Solution {
public:
    int father[200];
    int find(int x)
    {
        if (father[x] == x)
            return x;
        return find(father[x]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        int MSize = M.size();
        for(int i = 0; i < MSize; i ++)   
           father[i] = i;
            int ans = MSize;
        for(int i = 0; i < MSize; i ++)
        {
            for(int j = 0; j < i; j ++)
            {
                if(M[i][j] == 0) 
                    continue;
                if(find(father[i]) != find(father[j]))
                {
                    father[find(i)] = father[find(j)];
                    ans--;
                }
            }
        }
        return ans;
    }
};
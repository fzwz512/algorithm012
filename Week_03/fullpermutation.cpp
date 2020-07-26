class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int index = first; index < len; ++index) {
            swap(output[index], output[first]);
            backtrack(res, output, first + 1, len);
            swap(output[index], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
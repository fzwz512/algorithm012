class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (1 >= size)
            return size;
        int tmpindex = 0;
        for (int count = 1; count < size;  count++) {
            if (nums[count] != nums[tmpindex]) {
                    nums[++tmpindex] = nums[count];
            }
        }
        return ++tmpindex;
    }
};
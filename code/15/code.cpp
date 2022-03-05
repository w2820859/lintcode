class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        recur(0, nums);
        return _res;
    }

private:
    void recur(int pos, std::vector<int>& nums) {
        if (pos == nums.size()) _res.push_back(nums);
        for (int i = pos; i < nums.size(); ++i) {
            std::swap(nums[pos], nums[i]);
            recur(pos + 1, nums);
            std::swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> _res;
};

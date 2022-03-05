class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        results.push_back(res);
        _recur(nums, 0, res);
        return results;
    }

    void _recur(vector<int> &nums, int begin, std::vector<int>& res) {
        for (int idx = begin; idx < nums.size(); ++idx) {
            if (idx != begin && nums[idx] == nums[idx - 1]) continue;
            res.push_back(nums[idx]);
            results.push_back(res);
            _recur(nums, idx + 1, res);
            res.pop_back();
        }
    }

    std::vector<std::vector<int>> results;
};

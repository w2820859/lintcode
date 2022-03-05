class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        results.push_back(res);
        _recur(nums, 0, res);
        return results;
    }

    void _recur(vector<int>& nums, int begin, vector<int>& res) {
        for (int idx = begin; idx < nums.size(); ++idx) {
            res.push_back(nums[idx]);
            results.push_back(res);
            _recur(nums, idx + 1, res);
            res.pop_back();
        }
    }

    vector<vector<int>> results;
};

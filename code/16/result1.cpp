class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        recur(0, nums);
        return _res;
    }

    void recur(int pos, std::vector<int>& nums) {
        if (pos == nums.size()) _res.push_back(nums);
        std::set<int> history;
        for (int i = pos; i < nums.size(); ++i) {
            if (history.count(nums[i]) != 0) continue;
            history.insert(nums[i]);
            std::swap(nums[pos], nums[i]);
            recur(pos + 1, nums);
            std::swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> _res;
};

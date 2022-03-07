class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k) {
        vector<vector<int64_t>> dp(nums.size() + 1, vector<int64_t>(nums.size() - k + 1, INT_MIN));
        dp[0][0] = 0;
        for (int idx = 1; idx <= nums.size(); ++idx) {
            dp[idx][0] = dp[idx - 1][0] + nums[idx - 1];
        }
        for (int idx = 1; idx <= nums.size(); ++idx) {
            for (int drop_num = 1; drop_num <= nums.size() - k; ++drop_num) {
                if (drop_num > idx) break;
                if (drop_num == idx) {
                    dp[idx][drop_num] = 0;
                    continue;
                }
                dp[idx][drop_num] = max(dp[idx - 1][drop_num] + nums[idx - 1], dp[idx - 1][drop_num - 1]);
            }
        }
        for (int x = 1; x <= nums.size(); ++x) {
            ostringstream oss;
            for (int y = 0; y <= nums.size() - k; ++y) {
                oss << dp[x][y] << " ";
            }
            cout << oss.str() << endl;
        }
        int64_t ret = INT_MIN;
        for (int drop_num = 0; drop_num <= nums.size() - k; ++drop_num) {
            ret = max(ret, dp[nums.size()][drop_num]);
        }
        return ret;
    }
};

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        std::vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        for (int idx = 1; idx <= nums.size(); ++idx) {
            for (int i = 1; i <= idx; ++i) {
                int max_seq_len = 0;
                if (nums[idx - 1] >= nums[i - 1]) {
                    max_seq_len = max(max_seq_len, dp[i] + 1);
                }
                dp[idx] = max_seq_len;
            }
        }
        return dp[nums.size()];
    }
};

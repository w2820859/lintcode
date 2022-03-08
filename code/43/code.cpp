class Solution {
public:
    int maxSubArray(vector<int> &nums, int k) {
        vector<vector<vector<int64_t>>> dp(nums.size() + 1, vector<vector<int64_t>>(2, vector<int64_t>(k + 1, INT_MIN)));
        for (int idx = 1; idx <= nums.size(); ++idx) {
            dp[idx][0][0] = 0;
        }
        dp[1][1][1] = nums[0];
        for (int idx = 2; idx <= nums.size(); ++idx) {
            for (int n = 1; n <= k; ++n) {
                dp[idx][0][n] =  max(dp[idx - 1][0][n], dp[idx - 1][1][n]);
                dp[idx][1][n] = max(dp[idx - 1][0][n - 1] + nums[idx - 1], max(dp[idx - 1][1][n] + nums[idx - 1], dp[idx - 1][1][n - 1] + nums[idx - 1]));
            }
        }
        return max(dp[nums.size()][0][k], dp[nums.size()][1][k]);
    }
};

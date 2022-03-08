class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        vector<int> dp_left(nums.size(), 0);
        vector<int> dp_right(nums.size(), 0);
        int64_t prev_sum = INT_MIN;
        int64_t max_sum = INT_MIN;
        int ret = INT_MIN;
        for (int idx = 0; idx < nums.size(); ++idx) {
            int64_t combine = prev_sum + nums[idx];
            prev_sum = combine > nums[idx] ? combine : nums[idx];
            max_sum = max(max_sum, prev_sum);
            dp_left[idx] = max_sum;
        }
        prev_sum = INT_MIN;
        max_sum = INT_MIN;
        for (int idx = nums.size() - 1; idx >= 0; --idx) {
            int64_t combine = prev_sum + nums[idx];
            prev_sum = combine > nums[idx] ? combine : nums[idx];
            max_sum = max(max_sum, prev_sum);
            dp_right[idx] = max_sum;
        }
        for (int idx = 0; idx < nums.size() - 1; ++idx) {
            ret = max(ret, dp_left[idx] + dp_right[idx + 1]);
        }
        return ret;
    }
};

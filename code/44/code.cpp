class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        int64_t ret = INT_MAX;
        int64_t prev_sum = INT_MAX;
        for (int idx = 0; idx < nums.size(); ++idx) {
            int64_t conbined_sum = prev_sum + nums[idx];
            prev_sum = conbined_sum > nums[idx] ? nums[idx]: conbined_sum;
            ret = min(ret, prev_sum);
        }
        return ret;
    }
};

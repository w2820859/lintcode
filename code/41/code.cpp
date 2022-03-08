class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
       int ret = INT_MIN;
       int prev_sum = INT_MIN;
       for (int x : nums) {
           prev_sum = prev_sum + x > x ? prev_sum + x : x;
           ret = max(ret, prev_sum);
       }
       return ret;
    }
};

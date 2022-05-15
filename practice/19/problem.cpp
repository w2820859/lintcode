class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_sum = array[0];
        int sum = array[0];
        for (int i = 1; i < array.size(); ++i) {
            sum = max(sum + array[i], array[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

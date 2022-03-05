class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    void partition(std::vector<int>& datas, int front, int back, int pivot, int* stop) {
        int begin = front;
        int end = back;
        while (begin < end) {
            while (begin < end && datas[end - 1] >= pivot) end--;
            while (begin < end && datas[begin] < pivot) begin++;
            if (begin < end) {
                std::swap(datas[begin], datas[end - 1]);
            }
        }
        *stop = begin;
    }

    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        int begin = 0;
        int end = nums.size();
        int stop = -1;
        int pivot = 0;
        int nth_less_pos = nums.size() - n;
        while (stop != nth_less_pos) {
            pivot = nums[begin];
            partition(nums, begin, end, pivot, &stop);
            if (stop == nth_less_pos) break;
            if (stop > nth_less_pos) {
                end = stop;
            } else {
                if (begin == stop) {
                  begin = stop + 1;
                } else {
                  begin = stop;
                }
            }
        }
        return pivot;
    }
};

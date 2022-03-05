class Solution {
public:
    int kthLargestElement(int n, vector<int> &nums) {
        return find(0, nums.size() - 1, nums, n - 1);
    }
    int find(int begin_pos, int end_pos, std::vector<int>& nums, int target_pos) {
        int front_pos = begin_pos;
        int back_pos = end_pos;
        int pivot = nums[front_pos];
        while (front_pos < back_pos) {
            while (front_pos < back_pos && nums[back_pos] <= pivot) --back_pos; 
            nums[front_pos] = nums[back_pos];
            while (front_pos < back_pos && nums[front_pos] > pivot) ++front_pos; 
            nums[back_pos] = nums[front_pos];
        }
        nums[front_pos] = pivot;
        if (target_pos < front_pos) {
            return find(begin_pos, front_pos - 1, nums, target_pos);
        } else if (target_pos > front_pos) {
            return find(front_pos + 1, end_pos, nums, target_pos);
        }
        return pivot;
    }
};

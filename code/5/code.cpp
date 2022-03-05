class Solution {
public:
    int kthLargestElement(int n, vector<int> &nums) {
        return find(0, nums.size() - 1, nums, n - 1);
    }
    int find(int begin, int end, std::vector<int>& nums, int target) {
        int front = begin;
        int back = end;
        int pivot = nums[front];
        while (front < back) {
            while (front < back && nums[back] <= pivot) --back; 
            nums[front] = nums[back];
            while (front < back && nums[front] > pivot) ++front; 
            nums[back] = nums[front];
        }
        nums[front] = pivot;
        if (target < front) {
            return find(begin, front - 1, nums, target);
        } else if (target > front) {
            return find(front + 1, end, nums, target);
        }
        return pivot;
    }
};

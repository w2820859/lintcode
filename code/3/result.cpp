class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        for (int number = 0; number <= n; ++number) {
            int cur = number;
            do {
                int target = cur % 10;
                if (target == k) count++;
                cur = cur / 10;
            } while (cur != 0);
        }
        return count;
    }
};

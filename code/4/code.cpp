class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        std::set<int64_t> added;
        std::vector<int> array = {2, 3, 5};
        std::priority_queue<int64_t, std::vector<int64_t>, greater<int64_t>> pq;
        int64_t ret = 0;

        pq.push(1);
        for (int i = 0; i < n; ++i) {
            ret = pq.top();
            pq.pop();
            for (auto x : array) {
                int64_t n = x * ret;
                if (added.count(n) != 0) continue;
                added.insert(n);
                pq.push(n);
            }
        }
        return ret;
    }
};

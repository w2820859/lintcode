#include <algorithm>
#include <boost/algorithm/string/join.hpp>


std::string debug(std::vector<int>& v) {
    std::vector<std::string> temp;
    for (auto i : v) {
        temp.push_back(std::to_string(i));
    }
    return boost::join(temp, ",");
}

class Solution {
public:
    int kthLargestElement(int n, vector<int> &nums) {
        auto b = nums.begin();
        auto e = nums.end();
        while (true) {
            int pivot = *b;
            auto judge = [pivot] (int  x) {return x > pivot;};
            auto pos = std::partition(b, e, judge);
            if (pos == b) {
                while (pos != e && *pos == pivot) {
                    int order = pos - nums.begin() + 1;
                    if (order == n) {
                        return pivot;
                    }
                    ++pos;
                }
                if (pos == e) {
                    return pivot;
                } else {
                    b = pos;
                    continue;
                }
            }
            int order = pos - nums.begin() + 1;
            if (order > n) {
                e = pos;
            } else if (order < n) {
                b = pos;
            } else {
                return pivot;
            }
        }
        return -1;
    }
};

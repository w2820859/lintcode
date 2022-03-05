class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> ret;
        //ret.reserve(A.size() + B.size());
        auto a = A.begin();
        auto b = B.begin();
        while (a != A.end() && b != B.end()) {
            if (*a < *b) {
                ret.push_back(*a);
                ++a;
            } else {
                ret.push_back(*b);
                ++b;
            }
        }
        while (a != A.end()) {
            ret.push_back(*a);
            ++a;
        }
        while (b != B.end()) {
            ret.push_back(*b);
            ++b;
        }
        return ret;
    }
};

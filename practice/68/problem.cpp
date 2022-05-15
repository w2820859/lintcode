class Solution {
public:
    int jumpFloor(int number) {
        int p = 1;
        int pp = 1;
        int ret = 1;
        for (int i = 2; i <= number; ++i) {
            ret = p + pp;
            pp = p;
            p = ret;
        }
        return ret;
    }
};

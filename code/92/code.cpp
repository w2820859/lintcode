class Solution {
public:
    int backPack(int m, vector<int> array) {
        vector<int> pack(m+1, 0);
        pack[0] = 1;

        for (int idx = 0; idx < array.size(); ++idx) {
            for (int i = m - array[idx]; i >= 0; --i) {
                if (pack[i] != 0) {
                    pack[i + array[idx]] = 1;
                }
            }
        }
        for (int i = m; i > 0; --i) {
            if (pack[i] != 0) return i;
        }
    }
};

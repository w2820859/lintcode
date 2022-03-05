class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
/*
        int i = 1, j = 0;
        for (; i < s.size(); ++i) {
            if (s[i] == s[j]) {
                continue;
            } else {
                s[++j] = s[i];
            }
        }
        s.resize(j + 1);
*/
        vector<vector<int>> dp(s.size(), vector<int>(s.size() + 1, INT_MAX));
        for (int len = 1; len <= s.size(); ++len) {
            for (int begin = s.size() - len; begin >= 0; --begin) {
                if (len == 1) dp[begin][1] = 1;
                for (int left_len = 1; left_len <= len; ++left_len) {
                    int left_end_idx = begin + left_len - 1;
                    int left_step = begin != left_end_idx && s[begin] == s[left_end_idx] ? dp[begin][left_len - 1] : dp[begin][left_len];
                    int right_begin_idx = begin + left_len;
                    int right_len = len - left_len;
                    int right_step = left_len == len ? 0 : dp[right_begin_idx][right_len];
                    dp[begin][len] = min(dp[begin][len], left_step + right_step);
                }
            }
        }
        return dp[0][s.size()];
    }
};

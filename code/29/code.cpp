class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        for (int idx = 0; idx < s1.size(); ++idx) {
            if (s1[idx] == s3[idx]) {
                dp[idx + 1][0] = true;
            } else {
                break;
            }
        }
        for (int idx = 0; idx < s2.size(); ++idx) {
            if (s2[idx] == s3[idx]) {
                dp[0][idx + 1] = true;
            } else {
                break;
            }
        }
        for (int x = 1; x <= s1.size(); ++x) {
            for (int y = 1; y <= s2.size(); ++y) {
                if (dp[x - 1][y] == true && s3[x + y - 1] == s1[x - 1] ||
                    dp[x][y - 1] == true && s3[x + y - 1] == s2[y - 1]) {
                    dp[x][y] = true;
                } else {
                    dp[x][y] = false;
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

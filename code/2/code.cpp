class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        long long sum = 0;
        while (n) {
            sum += n / 5;
            n /= 5;
        }
        return sum;
    }
};

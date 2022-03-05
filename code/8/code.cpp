class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        if (str.empty()) return;
        offset = offset % str.size();
        int begin = 0, end = str.size() - offset;
        while (begin < end) swap(str[begin], str[end - 1]), ++begin, --end;
        begin = str.size() - offset; end = str.size();
        while (begin < end) swap(str[begin], str[end - 1]), ++begin, --end;
        begin = 0, end = str.size();
        while (begin < end) swap(str[begin], str[end - 1]), ++begin, --end;
    }
};

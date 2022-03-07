class Solution {
public:
    /**
     * @param c: A character.
     * @return: The character is alphanumeric or not.
     */
    bool isAlphanumeric(char c) {
        if ('a' <= c && 'z' >= c) return true;
        if ('A' <= c && 'Z' >= c) return true;
        if ('0' <= c && '9' >= c) return true;
        return false;
    }
};

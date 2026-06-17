class Solution {
public:
    char processStr(string s, long long k) {
        long long L = 0;
        for (char c : s) {
            if (c == '*') {
                if (L > 0) L--;
            } else if (c == '#') {
                L *= 2;
            } else if (c == '%') {
                continue;
            } else {
                L++;
            }
        }
        if (k >= L) return '.';
        long long p = k;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '*') {
                L++;
            } else if (c == '#') {
                if (p >= L / 2) {
                    p -= L / 2;
                }
                L /= 2;
            } else if (c == '%') {
                p = L - 1 - p;
            } else {
                if (L == p + 1) {
                    return c;
                }
                L--;
            }
        }
        return '.';
    }
};
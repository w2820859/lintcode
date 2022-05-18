#include "common_header.h"

string dump_str(const string& x) {
    return x;
}

string dump_int(int x) {
    return to_string(x);
}

string dump_vector_int(const vector<int>& x) {
    stringstream oss;
    if (x.empty()) {
        return "";
    } else {
        oss << x[0];
        for (int i = 1; i < x.size(); ++i) {
            oss << "," << x[i];
        }
    }
    return oss.str();
}

#pragma once
#include "common_header.h"

static string dump_string(const string& x) {
    string ret = "\"";
    ret += x;
    ret += '\"';
    return ret;
}

static string dump_int(int x) {
    return to_string(x);
}

static string dump_vector_int(const vector<int>& x) {
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

static string dump_set_int(const set<int>& x) {
    stringstream oss;
    if (x.empty()) {
        return "";
    } else {
        auto b = x.begin();
        oss << *b;
        ++b;
        for (; b != x.end(); ++b) {
            oss << "," << *b;
        }
    }
    return oss.str();
}

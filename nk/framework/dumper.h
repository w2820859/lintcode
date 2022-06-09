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

static string dump_bool(bool x) {
    if (x) return "true";
    return "false";
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

static string dump_vector_string(const vector<string>& x) {
    stringstream oss;
    if (x.empty()) {
        return "\"\"";
    } else {
        oss << '"' << x[0] << '"';
        for (int i = 1; i < x.size(); ++i) {
            oss << "," << '"' << x[i] << '"';
        }
    }
    return oss.str();
}

static string dump_vector_vector_int(const vector<vector<int>>& x) {
    stringstream oss;
    if (x.empty()) {
        return "";
    } else {
        for (const auto& item : x) {
            stringstream oss1;
            for (int i = 0; i < item.size(); ++i) {
                oss1 << item[i] << ",";
            }
            string str1 = oss1.str();
            str1.resize(str1.size() - 1);
            oss << str1 << "|";
        }
    }
    string ret = oss.str();
    ret.resize(ret.size() - 1);
    return ret;
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

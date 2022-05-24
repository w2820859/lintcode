#pragma once
#include "common_header.h"

static string parse_string(const string& str) {
    return str;
}

static int parse_int(const string& str) {
    return atoi(str.c_str());
}

static vector<int> parse_vector_int(const string& str) {
    stringstream ss(str) ;
    vector<int> ret;
    string s;
    while (getline(ss, s, ',')) {
        ret.push_back(atoi(s.c_str()));
    }
    return ret;
}

static set<int> parse_set_int(const string& str) {
    stringstream ss(str) ;
    set<int> ret;
    string s;
    while (getline(ss, s, ',')) {
        ret.insert(atoi(s.c_str()));
    }
    return ret;
}

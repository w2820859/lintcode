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

static vector<string> parse_vector_string(const string& str) {
    stringstream ss(str) ;
    vector<string> ret;
    string s;
    while (getline(ss, s, ',')) {
        ret.push_back(s);
    }
    return ret;
}

static vector<vector<int>> parse_vector_vector_int(const string& str) {
    stringstream ss(str) ;
    vector<vector<int>> ret;
    string s;
    vector<string> temp;
    while (getline(ss, s, '|')) {
        temp.push_back(s);
    }
    for (auto s1 : temp) {
        stringstream ss1(s1);
        vector<int> item;
        while (getline(ss1, s, ',')) {
            item.push_back(stoi(s));
        }
        ret.push_back(item);
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

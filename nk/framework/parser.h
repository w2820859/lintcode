#include "common_header.h"

string parse_string(const string& str) {
    return str;
}

int parse_int(const string& str) {
    return atoi(str.c_str());
}

vector<int> parse_vector_int(const string& str) {
    stringstream ss(str) ;
    vector<int> ret;
    string s;
    while (getline(ss, s, ',')) {
        ret.push_back(atoi(s.c_str()));
    }
    return ret;
}

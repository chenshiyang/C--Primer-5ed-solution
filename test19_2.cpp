#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "test19_2_StrVec.h"

using namespace std;

int main() {
    StrVec sv;
    sv.push_back("hello");
    sv.push_back("world");
    sv.push_back("secret");
    for_each(sv.begin(), sv.end(), [](const string &s) { cout << s << endl; });
//    sv.resize(10);
//    for_each(sv.begin(), sv.end(), [](const string &s) { cout << s << endl; });
    return 0;
}

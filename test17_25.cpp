#include <iostream>
#include <string>
#include <regex>

using namespace std;
using namespace std::regex_constants;

int main() {
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    string s;
    string fmt = "$2.$5.$7";
    while(getline(cin, s)) {
        cout << regex_replace(s, r, fmt, match_prev_avail) << endl;
    }
    return 0;
}


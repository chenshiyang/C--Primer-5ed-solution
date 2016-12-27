#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string pattern("(\\d{5})(\\d{4})");
    regex r(pattern);
    smatch m;
    string s;
    string fmt = "$1-$2";
    while(getline(cin, s)) {
        cout << regex_replace(s, r, fmt) << endl;
    }

    return 0;
}

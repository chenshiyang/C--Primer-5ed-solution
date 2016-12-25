#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string zipcode("(\\d{5})([-]?\\d{4})?");
    regex r(zipcode);
    string s;
    smatch m;
    while(getline(cin, s)) {
        if(regex_match(s, m, r)) {
            cout << "valid: " << m.str() << endl;
        } else {
            cout << "invalid: " << m.str() << endl;
        }
    }
    return 0;
}

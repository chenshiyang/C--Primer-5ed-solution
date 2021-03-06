#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool valid(const smatch &m) {
    if(m[1].matched) {
        return m[3].matched && m[4].matched == 0;
    } else {
        return m[3].matched == 0 && m[4].str() == m[7].str();
    }
}

int main() {
    string phone = "(\\()?(\\d{3})(\\))?([-.])?([ ]+)?(\\d{3})([-.])?([ ]+)?(\\d{4})";
    regex r(phone);
    string s;
    while(getline(cin, s)) {
        for(sregex_iterator it(s.begin(), s.end(), r), it_end; it != it_end; ++ it) {
            if(valid(*it)) {
                cout << "valid: " << it -> str() << endl;
            } else {
                cout << "not valid: " << it -> str() << endl;
            }
        }
    }
    return 0;
}

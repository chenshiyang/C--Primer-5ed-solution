#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    string pattern2("[^c]ei");//required by test 17.16
    regex r(pattern2);
    string s;
    smatch results;
    while(cin >> s) {
        if(regex_match(s, results, r)) {
            cout << s << " violates rule." << endl;
        } else {
            cout << s << " is good." << endl;
        }
    }
    return 0;
}

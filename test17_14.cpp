#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    try {
        //[z-a]+\\.(cpp|cxx|cc)$   code 4
        //
        string pattern("[[:alnum:]]+\\.cpp|cxx|cc)$", regex::icase);
        regex r(pattern);
        smatch results;
    } catch(regex_error e) {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }

    return 0;
}

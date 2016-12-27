#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main() {
//    string pattern("[^c]ei");
//    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
//    regex r(pattern);
//    smatch results;
//    string test_str = "receipt  theif receive";
//    if(regex_search(test_str, results, r)) {
//        cout << results.str() << endl;
//    }

    //test p648
    try {
        regex r2("[[:alnum]+\\.(cpp|cxx|cc)$", regex::icase);
    } catch(regex_error e) {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
}

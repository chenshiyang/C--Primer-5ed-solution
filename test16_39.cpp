#include <iostream>
#include <string>

#include "test16_2_compare.h"

using namespace std;

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) {
    return *beg;
}


int main() {
    cout << compare<char*>("hi", "world") << endl;
    cout << compare<string>("dad", "bye") << endl;
    return 0;
}

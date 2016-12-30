#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;
using std::placeholders::_1;

int main() {
    vector<string> svec = {"", "a", "", "b", "c"};
    //use mem_fn
    cout << count_if(svec.cbegin(), svec.cend(), mem_fn(&string::empty)) << " strings are empty" << endl;
    //use function
    function<bool (const string&)> fcn = &string::empty;
    cout << count_if(svec.cbegin(), svec.cend(), fcn) << " strings are empty" << endl;
    //use bind
    cout << count_if(svec.cbegin(), svec.cend(), bind(&string::empty, _1)) << " strings are empty" << endl;
    return 0;
}

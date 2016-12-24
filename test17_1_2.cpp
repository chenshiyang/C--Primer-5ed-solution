#include <iostream>
#include <tuple>
#include <vector>
#include <utility>

using namespace std;

int main() {
    //test 17.1
    auto ituple = make_tuple(10, 20, 30);
    size_t sz = tuple_size<decltype(ituple)>::value;
    cout << sz << endl;
//    for(size_t i = 0; i != sz; ++ i) {
//            const size_t ii = i;
//        cout << get<ii>(ituple) << ends;
//    }
    cout << endl;

    //test 17.2
    tuple<string, vector<string>, pair<string, int>> t("string", {"string", "in", "vector"}, {"string in pair", 0});
    cout << get<0>(t) << endl;
    cout << get<1>(t)[0] << endl;
    cout << get<2>(t).first << endl;
    return 0;
}

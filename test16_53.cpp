#include <iostream>
#include <string>

using namespace std;

//template <typename T>
//void print(ostream& os, const T &t) {
//    os << t;
//}

template <typename T, typename... Args>
void print(ostream &os, const T &t, const Args&... args) {
    os << t << ",";
    print(os, args...);
}

template <typename T>
void print(ostream& os, const T &t) {
    os << t;
}

class F {
public:
    int i = 0;
};

int main() {
    int i = 1;
    string s = "string";
    print(cout, i, s, 42);
    cout << endl;
    print(cout, 42);
    cout << endl;
    print(cout, 42, "end");

    //test 16.54
//    print(cout, F());
    return 0;
}

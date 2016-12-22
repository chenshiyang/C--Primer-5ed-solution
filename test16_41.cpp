#include <iostream>
#include <limits>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    char c1 = 127;
    char c2 = 127;
    long lng = numeric_limits<long>::max() - 200;
    cout << sum(c1, c2) << endl;
    cout << sum(c2, lng) << endl;
    return 0;
}

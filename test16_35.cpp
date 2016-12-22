#include <iostream>

using namespace std;

template <typename T>
T calc(T a, int i) {
    return a;
}

template <typename T>
T fcn(T a, T b) {
    return a;
}

int main() {
    double d;
    float f;
    char c = 'a';
    calc(c, 'c');//good
    calc(d, f);//good
    cout << fcn(c, 'c');
//    fcn(d, f);
}

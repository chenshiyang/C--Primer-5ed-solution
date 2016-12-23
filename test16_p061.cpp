#include <iostream>
#include<string>

using namespace std;

template <typename T>
T fobj(T a, T b) {
    return a;
}

template <typename T>
void fref(const T &a, const T &b) {

}

int main() {
    string s1("a value");
    const string s2("another value");
    fobj(s1, s2);
    fref(s1, s2);

    int a[10], b[10];
    fobj(a, b);
    fref(a, b);
    return 0;
}

#include<iostream>

using namespace std;

int main() {
    //int i = 01, &r = 0;//error
//    const int i = 01, &r = 0;
//    int null = 0, *p = null;//error
//    const int null = 0, *p = null;//error
//    constexpr int null = 0, *p = null;
//    auto sz = 0, pi = 3.14;//error
//    auto i = 0, *p = &i;

//    const int i = 42;
//    auto j = i;
//    cout << j << endl;
//    j = 5;
//    cout << j << endl;

//    int a = 3, b = 4;
//    decltype(a) c = a;
//    decltype((b)) d = a;
//    ++c;
//    ++d;
//    cout << a << endl;
//    cout << b << endl;
//    cout << c << endl;
//    cout << d << endl;

    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    c = 5;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}

#include <iostream>
#include <string>

using namespace std;

template <typename T>
void g(T &&val) {
    T t = val;
    t -= 1;//for test
    if(val == t) {
        cout << "T is reference" << endl;
    } else {
        cout << "T is not reference" << endl;
    }
}

template <typename T>
void g3(const T& val) {
    T t = val;
    t -= 1;//for test
    if(val == t) {
        cout << "T is reference" << endl;
    } else {
        cout << "T is not reference" << endl;
    }
}

int main() {
    //test 16.42
    int i  = 0;
    const int ci = i;
    g(i);// T is int&
//    g(ci);// T is const int &
    g(i * ci);//T is int
    g(i = ci);


    //test 16.44
    g3(i);
    g3(ci);
    g3(i * ci);
}

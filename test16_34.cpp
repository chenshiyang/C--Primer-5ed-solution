#include <iostream>
#include <string>

using namespace std;

template <typename T>
int compare(const T &l , const T &r) {//remove the &, then works.
    if(l > r) return 1;
    if(r > l) return -1;
    return 0;
}

int main() {
//    cout << compare("hi", "world");
    cout << compare("bye", "dad");
    return 0;
}

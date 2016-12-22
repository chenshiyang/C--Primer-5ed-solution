#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p;
    if(p) {
        ret << " content: " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str();
}

string debug_rep(const string &s) {
    return '"' + s + '"' + "no template";
}

int main() {
    string s("hi");
    cout << debug_rep(s) << endl;//call debug_rep(const T&t), T is string, when the third function is commented
    cout << debug_rep(&s) << endl;//call debug_rep(T*p), T is string

    const string *sp = &s;
    cout << debug_rep(sp) << endl;//call debug_rep(T* p), T is const string, this one is more specialize

    //const char*
    cout << debug_rep("hi world!") << endl;
}

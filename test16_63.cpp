#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//solution for test 16.63 16.64

template <typename T>
typename vector<T>::size_type countTimes(const vector<T> &vec, const T &target) {
    typename vector<T>::size_type time = 0;
    for(auto elem : vec) {
        if(elem == target) {
            ++ time;
        }
    }
    return time;
}

template <>
vector<const char*>::size_type countTimes(const vector<const char*> &vec, const char* const &target) {
    cout << "specialization  " << ends;
    vector<const char*>::size_type time = 0;
    for(auto elem : vec) {
        if(strcmp(elem, target) == 0) {
            ++ time;
        }
    }
    return time;
}

int main() {
    vector<int> ivec = {1, 2, 2, 3, 4, 1, 2, 4, 6};
    cout << countTimes(ivec, 2) << endl;
    vector<double> dvec = {1.0, 2.0, 3.0, 2.0, 4.0, 1.0, 2.0};
    cout << countTimes(dvec, 1.0) << endl;
    vector<const char*> cvec = {"a", "b", "a", "c"};
    const char* c = "f";
    cout << countTimes(cvec, c) << endl;
    vector<string> svec = {"a", "b", "a", "c"};
    string s = "f";
    cout << countTimes(svec, s) << endl;
}

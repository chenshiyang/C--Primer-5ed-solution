#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<cstring>

using namespace std;

int main() {
//    string word;
//    vector<string> text;
//    while(cin >> word) {
//        text.push_back(word);
//    }
//    for(string &s : text) {
//        for(char &c : s) {
//            c = toupper(c);
//        }
//        cout << s << endl;
//    }
//
//    for(decltype(text.size()) i = 0; i < text.size(); ++i) {
//        cout << text[i] << endl;
//    }
//
//    for(auto ss = text.begin(); ss != text.end(); ++ss) {
//        cout << *ss << endl;
//    }


//    const vector<int> ivec{1, 2, 3};
//    const int i = 4;
//    ivec.push_back(i);



//test 3.23
//    vector<int> ivec(10, 3);
//    for(auto it = ivec.begin(); it != ivec.end(); ++it) {
//        *it *= 2;
//    }
//    for(int &i : ivec) {
//        cout << i << endl;
//    }

//test array initialization need a constexpr?
//    const unsigned n = 3;
//    int array[n] = {1, 2};
//    for(auto &i : array) {
//            i *= 2;
//        cout << i;
//    }

//test use an array to initialize another array


//test c++11's begin and end function for array, need to include<iterator>
//    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int * beg = begin(ia);
//    int * last = end(ia);
//    for(; beg != last; ++beg) {
//        *beg *= 3;
//        cout << *beg << endl;
//    }

//    constexpr size_t sz = 5;
//    int array[sz] = {1, 2, 3, 4, 5};
//    int *ip = array;
//    int *p = array + sz;
//    int *p2 = array + 10;
//    cout << *ip << endl;
//    cout << *p << endl;
//    cout << *p2 << endl;

//test functions in cstring
//    char ca[] = {'a', 'b', 'c', '\0'};
//    char ca2[] = {'d', 'e', 'f', '\0'};
//
//    cout << strcmp(ca, ca2) << endl;
//    cout << strlen(ca) << endl;
//    cout << strcat(ca, ca2) << endl;
//    cout << strcpy(ca, ca2) << endl;


//test3.37
    const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char *cp = ca;
    while(*cp) {
        cout << *cp << endl;
        ++cp;
    }

    return 0;
}

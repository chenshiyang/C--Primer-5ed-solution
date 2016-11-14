#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
//    //test p 123
//    int i  = 0;
//    cout << i << " " << ++ i << endl;

//test 4.21
//    vector<int> ivec = {1, 2, 3, 4, 5};
//    for(auto it = ivec.begin(); it != ivec.end(); ++it) {
//        *it = (*it % 2 == 0) ? *it : *it * 2;
//        cout << *it << endl;
//    }

//test 4.23
//    string s = "word";
//    string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
//    cout << p1 << endl;

//test sizeof
//    int i = 5;
//    cout << sizeof(int) << endl;
//    cout << sizeof(i) << endl;
//
//    cout << sizeof(bool) << endl;//1
//    cout << sizeof(char) << endl;//1
//    cout << sizeof(int) << endl;//4
//    cout << sizeof(long) << endl;//4
//    cout << sizeof(float) << endl;//4
//    cout << sizeof(double) << endl;//8
//    cout << sizeof(long long) << endl;//8
//    cout << sizeof(long double) << endl;//12
//    cout << sizeof(int*) << endl;//4
//    cout << sizeof(double*) << endl;//4
//    double *pd;
//    cout << sizeof(*pd) << endl;//8, double's size
//    cout << sizeof(pd) << endl;//4 pointer's size
//
//    cout << sizeof(string) << endl;//4
//    cout << sizeof(vector<double>) << endl;//12
//    int array[] = {1,2,3};
//    cout << sizeof(array) << endl;


//test 5.17
//    vector<int> ivec1 = {0, 1, 1, 2};
//    vector<int> ivec2 = {0, 1, 1, 3, 3, 5, 8};
//    decltype(ivec1.size()) sz1 = ivec1.size();
//    decltype(ivec2.size()) sz2 = ivec2.size();
//    decltype(sz1) len = sz1 <= sz2 ? sz1 : sz2;
//    bool isPre = true;
//    for(decltype(ivec1.size()) i = 0; i < len; ++i) {
//        if(ivec1[i] != ivec2[i]) {
//            isPre = false;
//            break;
//        }
//    }
//    cout << isPre << endl;


//test 5.19
    do {
        cout << "Please input two strings:" << endl;
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        cout << "The shorter is: \n" << (s1.size() <= s2.size() ? s1 : s2) << endl;
    } while(cin);
    return 0;
}

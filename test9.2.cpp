#include<vector>
#include<iostream>
#include<list>
#include<deque>
#include<forward_list>

using namespace std;

//test 9.4
//bool find_element(vector<int> &ivec, int val) {
//    for(auto itr = ivec.cbegin(); itr != ivec.cend(); ++ itr) {
//        if(*itr == val) {
//            return true;
//        }
//    }
//    return false;
//}


//test 9.28
void find_and_insert(forward_list<string> &fls, const string &s1, const string &s2) {
    auto itr = fls.begin();
    auto prev = fls.before_begin();
    while(itr != fls.end()) {
        if(*itr == s1) {
            itr = fls.insert_after(itr, s2);
            return;
        }
        prev = itr;
        ++ itr;
    }
    if(itr == fls.end()) {
        fls.insert_after(prev, s2);
    }
}

int main() {
    //test 9.2
//    list<deque<int>> ls;
//    deque<int> dq{1, 2, 3};
//    deque<int> dq2{3, 2, 1};
//    ls.push_back(dq);
//    ls.push_back(dq2);
//
//    for(auto p1 = ls.cbegin(); p1 != ls.cend(); ++ p1) {
//        for(auto p2 = (*p1).cbegin(); p2 != (*p1).cend(); ++ p2) {
//            cout << *p2 << ends;
//        }
//        cout << endl;
//    }

//test 9.4
//    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8};
//    cout << find_element(ivec, 6) << endl;
//    cout << find_element(ivec, 9) << endl;

//test 9.13
//    list<int> ls{1, 2, 3, 4, 5};
//    auto bg = ls.cbegin();
//    auto ed = ls.cend();
//    vector<double> dvec(bg, ed);
//    dvec.push_back(6);
//    for(auto d : dvec) {
//        cout << d << ends;
//    }
//    cout << endl;
//
//    vector<double> dvec2(dvec);
//        for(auto d : dvec2) {
//        cout << d << ends;
//    }
//    cout << endl;

//test 9.14
//    list<const char*> names = {"I", "am", "Undead"};
//    vector<string> svec;
//    svec.assign(names.begin(), names.end());
//    for(auto s : svec) {
//        cout << s << ends;
//    }

//test 9.18
//    string s;
//    deque<string> dq;
//    while(cin >> s) {
//        dq.push_back(s);
//    }
//    for(auto itr = dq.cbegin(); itr != dq.cend(); ++ itr) {
//        cout << *itr << ends;
//    }
//    cout << endl;

//test 9.19
//    string s;
//    list<string> ls;
//    while(cin >> s) {
//        ls.push_back(s);
//    }
//    for(auto itr = ls.cbegin(); itr != ls.cend(); ++ itr) {
//        cout << *itr << endl;
//    }

//test 9.21

//test 9.25
//    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7};
//    auto bg = lst.begin();
//    auto ed = lst.end();
//    lst.erase(bg, ed);
//    for(auto i : lst) {
//        cout << i << ends;
//    }


//test 9.26
//    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
//    vector<int> ivec(ia, ia + 11);
//    list<int> lst(ia, ia + 11);
//    for(auto itr = ivec.begin(); itr != ivec.end();) {
//        if(*itr % 2 != 0) {
//            itr = ivec.erase(itr);
//        } else {
//            ++ itr;
//        }
//    }
//
//    for(auto itr = lst.begin(); itr != lst.end();) {
//        if(*itr % 2 == 0) {
//            itr = lst.erase(itr);
//        } else {
//            ++ itr;
//        }
//    }
//    for(auto i : ivec) {
//        cout << i << ends;
//    }
//    cout << endl;
//    for(auto i : lst) {
//        cout << i << ends;
//    }
//    cout << endl;

//test 9.27
//    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7};
//    auto prev = flst.before_begin();
//    auto curr = flst.begin();
//    while(curr != flst.end()) {
//        if(*curr % 2 != 0) {
//            curr = flst.erase_after(prev);
//        } else {
//            prev = curr;
//            ++ curr;
//        }
//    }
//
//    for(auto i : flst) {
//        cout << i << ends;
//    }

//test 9.28
//    forward_list<string> fls = {"a", "b", "c", "d", "f"};
//    string s1("g");
//    string s2("e");
//    find_and_insert(fls, s1, s2);
//    for(auto s : fls) {
//        cout << s << ends;
//    }

//test 9.31


//test 9.41
    vector<char> cv = {'h', 'e', 'h', 'e', '\0'};
    auto bg = cv.begin();
    string s(bg, cv.end());
    cout << s << endl;
    return 0;
}

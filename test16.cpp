#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>

#include "test14_6_Sales_data.h"
#include "test16_12_Blob.h"
#include "test16_21_DebugDelete.h"

using namespace std;

//test 16.2
template <typename T>
int compare(const T &l, const T &r) {
    if(l < r) { return -1; }
    if(r < l) { return 1; }
    return 0;
}


//test 16.4 use template to implement find() algorithm
template <typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T &val) {
    while(first != last) {
        if(*first == val) { return first; }
        ++ first;
    }
    return last;
}


//test 16.5 use template to implement print()
template <typename T, size_t N>
void print(const T(&p)[N]) {
    for(size_t i = 0; i != N; ++ i) {
        cout << *(p + i) << ends;
    }
    cout << endl;
}


//test 16.6 use template to implement begin()
template <typename T, size_t N>
T* begin(const T(&p)[N]) {
    return p;
}

//test 16.6 use template to implement end()
template <typename T, size_t N>
T* end(const T(&p)[N]) {
    return (p + N);
}

//test 16.7 implement a constexpr template to return the size of a given array
template <typename T, size_t N>
constexpr size_t size(const T(&p)[N]) {
    return N;
}


//test 16.11
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();

    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};


//test 16.19
template <typename T>
void print(const T& t) {
    for(typename T::size_type i = 0; i != t.size(); ++ i) {
        cout << t[i] << ends;
    }
    cout << endl;
}

//test 16.20
template <typename T>
void print2(const T& t) {
    for(auto itr = t.begin(); itr != t.end(); ++ itr) {
        cout << *itr << ends;
    }
    cout << endl;
}


int main() {
    //test 16.2
//    string s1("abc");
//    string s2("acd");
//    cout << compare(s1, s2) << endl;
//    cout << compare(2, 1) << endl;
//    vector<int> vi1 = {1, 2, 3};
//    vector<int> vi2 = {1, 2, 3, 4};
//    cout << compare(vi1, vi2) << endl;
//    cout << compare(vi2, vi1) << endl;
//    cout << compare(vi1, vi1) << endl;

    //test 16.3
//    Sales_data sd1("book1", 123, 30.0);
//    Sales_data sd2("book2", 321, 30.2);
//
//    cout << compare(sd1, sd2) << endl;
//    cout << compare(sd2, sd1) << endl;

    //test 16.4
//    vector<int> vi = {6, 4, 3, 5, 1, 9};
//    int target = 5;
//    auto res = find(vi.cbegin(), vi.cend(), target);
//    if(res == vi.cend()) {
//        cout << target << " is not in vector." << endl;
//    } else {
//        cout << target << " is the " << res - vi.begin() << "th element." << endl;
//    }
//
//    list<string> slist = {"wind", "become", "curiosity"};
//    string starget = "wind";
//    auto res2 = find(slist.cbegin(), slist.cend(), starget);
//    if(res2 == slist.cend()) {
//        cout << starget << " is not in list." << endl;
//    } else {
//        cout << starget << " is the " << distance(res2, slist.cbegin()) << "th element." << endl;//here we can only use distance()
//    }


    //test 16.5
//    print("interestring");
//    int array1[] = {1, 2, 3, 4, 5};
//    print(array1);

    //test 16.6,   test the function of my begin() and end()
//    int array1[] = {1, 2, 3, 4, 5, 6};
//    for(auto itr = begin(array1); itr != end(array1); ++ itr) {
//        cout << *itr << ends;
//    }
//    cout << endl;
//    string sarry[] = {"break", "a", "bone", "sick", "like", "a", "disease"};
//    for(auto itr = begin(sarry); itr != end(sarry); ++ itr) {
//        cout << *itr << ends;
//    }
//    cout << endl;


    //test 16.7
//    int array[] = {1, 2, 3, 4, 5, 6};
//    cout << size(array) << endl;
//    string sarry[] = {"a", "b", "c", "d"};
//    cout << size(sarry) << endl;


    //test 16.19
//    vector<int> vi = {1, 2, 3, 4, 5, 6, 7};
//    print(vi);

    //test 16.20
//    vector<int> vi = {1, 2, 3, 4, 5, 6, 7};
//    print2(vi);


    //test 16.21
//    double *p = new double;
//    DebugDelete()(p);
//
//    unique_ptr<int, DebugDelete> up(new int, DebugDelete());


    //test 16.37
    int i = 1;
    double d = 1.1;
    cout << max(i, d);
}

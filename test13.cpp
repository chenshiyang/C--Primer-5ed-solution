#include<iostream>
#include<algorithm>
#include "test13_34_Message.h"
#include "test13_39_StrVec.h"
#include "test13_56_Foo.h"


using namespace std;

//test 13.4
//class Point {
//public:
//
//    Point() {}
//    Point(const Point &p) {
//        cout << "copy constructor" << endl;
//    }
//};
//    Point global;
//Point foo_bar(Point arg) {//one copy
//    Point local = arg;//one copy constructor
//////    Point *heap = new Point(global);//one copy constructor
////    Point *heap = &local;//no copy constuctor
////    *heap = local;//no copy constructor
////    Point pa[4] = {local, *heap};//two copy constructor
//    return *heap;//one copy
//}

//test 13.5 and 13.11
class HasPtr {
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0) {}
    //copy constructor
    HasPtr(const HasPtr &hp) :
        ps(new string(*(hp.ps))), i(hp.i) {}

    ~HasPtr() {
        delete ps;
        cout << "destructor" << endl;

    }

    string get_str() const{ return *ps; }
    void set_str(const string &s) { *ps = s; }
private:
    string *ps;
    int i;
};

//test 13.12
//bool fcn(const HasPtr * trans, HasPtr accum) {//two destructor
//    HasPtr hp(*trans);//no destructor
//    HasPtr hp2(accum);//one destructor
//    return true;
//}


//test 13.14
class numbered {
public:
    numbered() {}
    numbered(const numbered &n) {
        mysn = n.mysn + 2;
        cout << "numbered()" << endl;
    }

    int mysn;
};

void f(const numbered &s) { cout << s.mysn << endl;}

int main() {

//test 13.4
//    Point arg;
//    foo_bar(arg);

//test 13.5
//    HasPtr hp("original");
//    HasPtr newhp = hp;
//    hp.set_str("changed");
//    cout << hp.get_str() << endl;
//    cout << newhp.get_str() << endl;

//test 13.12 count the number of destructor call
//    HasPtr hp, hp2;
//    HasPtr *trans = &hp;
//    fcn(trans, hp2);

//test 13.14
//    numbered a, b = a, c = b;
//    f(a);
//    f(b);
//    f(c);

//    int *p1 = nullptr;
//    int *p2 = nullptr;
//    cout << p1 - p2 << endl;

//test 13.34 13.36 13.37
//    Message m1("To Mr Chen");
//    m1.show();
//    Message m2 = m1;
//    m2.show();
//    Folder f1("folder1");
//    Folder f2("folder2");
//    m1.save(f1);
//    m1.show();
//    f1.show();
//    f2.show();
//    f2.addMsg(&m2);
//    f2.show();

//test 13.39 43
//    StrVec sv;
//    sv.push_back("hello");
//    sv.push_back("world");
//    sv.push_back("secret");
//    for_each(sv.begin(), sv.end(), [](const string &s) { cout << s << endl; });
//    sv.resize(10);
//    for_each(sv.begin(), sv.end(), [](const string &s) { cout << s << endl; });


//test 13.56 13.57 13.58
//    Foo foo = {4, 3, 2, 1, 6};
//    foo.show();
//    Foo foo2 = foo.sorted();
//    foo2.show();

    const Foo foo3 = {4, 3, 2, 1, 6};
    foo3.sorted().show();


    return 0;
}

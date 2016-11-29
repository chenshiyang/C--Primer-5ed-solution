
#ifndef TEST13_56_FOO_H
#define TEST13_56_FOO_H

#include<vector>
#include<initializer_list>
#include<algorithm>


class Foo {
public:
    Foo(initializer_list<int>);
    Foo sorted() &&;
    Foo sorted() const &;
    void show() const;
private:
    vector<int> data;
};

Foo::Foo(initializer_list<int> il) {
    for(auto bg = il.begin(); bg != il.end(); ++ bg) {
        data.push_back(*bg);
    }
}

Foo Foo::sorted() && {
    cout << "sort() &&" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    cout << "sort() const &" << endl;
//    Foo ret(*this);
//    sort(ret.data.begin(), ret.data.end());
//    return ret;

//test13.56
//    Foo ret(*this);
//    return ret.sorted();

//test 13.57
    return Foo(*this).sorted();
}

void Foo::show() const {
    for(auto i : data) {
        cout << i << ends;
    }
    cout << endl;
}

#endif // TEST13_56_FOO_H

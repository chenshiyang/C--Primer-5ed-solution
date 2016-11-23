#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<fstream>
#include<cstring>

using namespace std;
//test 12.2
class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    StrBlobPtr begin();
    StrBlobPtr end();

    void push_back(const string &t) {data->push_back(t);}
    void pop_back();

    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

    void print() {
        auto vec = *data;
        for(auto s : vec) {
            cout << s << ends;
        }
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;

};

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) {}
    string& deref() const;
    StrBlobPtr& incr();
private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if(i >= data->size()) {
        throw out_of_range(msg);
    }
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if(!ret) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

//test 12.6
vector<int>* fill_vector(istream &in, vector<int> *pvec) {
    int i;
    while(in >> i) {
        pvec->push_back(i);
    }
    return pvec;
}

//test 12.6
vector<int>* print_vector(ostream &out, vector<int> *pvec) {
    vector<int> &vec = *pvec;
    for(auto i : vec) {
        out << i << ends;
    }
    out << endl;
    return pvec;
}

//test 12.7
void fill_vector(istream &in, shared_ptr<vector<int>> pvec) {
    int i;
    while(in >> i) {
        pvec->push_back(i);
    }
}

//test 12.7
void print_vector(ostream &out, shared_ptr<vector<int>> pvec) {
    vector<int> &vec = *pvec;
    for(auto i : vec) {
        out << i << ends;
    }
    out << endl;
}

//test 12.10
void process(shared_ptr<int> ptr) {
    cout << "process" << endl;
}

int main() {
    //test p401
//    auto p = make_shared<vector<string>>();
//    auto q(p);
//    cout << p.unique() << endl;
//    cout << p.use_count() << endl;
//    cout << q.unique() << endl;
//    cout << q.use_count() << endl;

//test 12.2
//    StrBlob b1;
//    {
//        StrBlob b2 = {"a", "b", "c"};
//        b1 = b2;
//        b2.push_back("d");
//    }
//    b1.print();

//test new delete
//    int *p1 = new int(2);
//    if(p1) {
//        cout << *p1 << endl;
//    } else {
//        cout << "invalid" << endl;
//    }
//    delete(p1);
//    p1 = nullptr;//good habit to set pointer to nullptr after delete.
//    if(p1) {
//        cout << *p1 << endl;
//    } else {
//        cout << "invalid" << endl;
//    }


//test 12.6
//    vector<int>* pvec = new vector<int>();
//    pvec = fill_vector(cin, pvec);
//    pvec = print_vector(cout, pvec);
//    delete pvec;
//    pvec = nullptr;


//test 12.7
//    shared_ptr<vector<int>> pvec = make_shared<vector<int>>();
//    fill_vector(cin, pvec);
//    print_vector(cout, pvec);

//test 12.10 and test 12.11
//    shared_ptr<int> p(new int(42));
//    cout << *p << endl;
//    process(shared_ptr<int>(p));
//    cout << p.use_count() << endl;
//    cout << *p << endl;
//
//    process(shared_ptr<int>(p.get()));
//    cout << p.use_count() << endl;
//    cout << *p << endl;

//test 12.13
//    auto sp = make_shared<int>(2);
//    auto p = sp.get();
//    delete p;
//    cout << *sp << endl;//2
//    cout << *p << endl;//2
//    cout << *sp.get() << endl;//2

//test 12.16
//    unique_ptr<int> p1(new int(10));
////    unique_ptr<int> p2(p1);
//    unique_ptr<int> p3 = p1;

//test 12.19 and test 12.20
//    ifstream in("test12.20.txt");
//    string line;
//    StrBlob b;
//    while(getline(in, line)) {
//        b.push_back(line);
//    }
//    auto ed = b.end();
////    for(auto itr = b.begin(); itr. != ed; itr = itr.incr()) { //no != operaration for StrBlobPtr, so we use try catch to traverse the vector.
////        cout << itr.deref() << endl;
////    }
//    auto bg = b.begin();
//    try {
//        while(true) {
//            cout << bg.deref() << endl;
//            bg = bg.incr();
//        }
//    } catch(out_of_range oor) {
//        cout << oor.what() << endl;
//    }


//test dynamic array
//    string *psa = new string[10]{"I", "am", "a", "hero"};
//    for(int i = 0; i != 10; ++ i) {
//        cout << *(psa + i) << ends;
//    }
//    cout << endl;
//    delete [] psa;

//test 12.23
//    const char* cstr1 = "I am";
//    const char* cstr2 = " a hero";
//    auto cp = new char[strlen(cstr1) + strlen(cstr2) + 1];// include the "\0"
//    strcpy(cp, cstr1);
//    strcat(cp, cstr2);
//    cout << cp << endl;
//    delete [] cp;
//
//    string str1("I am");
//    string str2(" a hero");
//    string str = str1 + str2;
//    cout << str << endl;

//test 12.24
//    string line;
//    while(getline(cin, line)) {
//        auto cp = new char[line.size() + 1];
//        strcpy(cp, line.c_str());
//        cout << cp << endl;
//        delete [] cp;
//    }


//test 12.26
    allocator<string> alloc;
    size_t n = 20;
    auto const p = alloc.allocate(n);
    string line;
    auto q = p;
    //construct
    while(getline(cin, line)) {
        alloc.construct(q ++, line);
    }
    const size_t size = q - p;
    //print
    auto r = p;
    while(r != q) {
        cout << *r ++ << endl;
    }
    //destroy
    while(q != p) {
        alloc.destroy(--q);
    }
    //deallocate
    alloc.deallocate(p, n);


    return 0;
}




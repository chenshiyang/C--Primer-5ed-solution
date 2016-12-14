#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iterator>
#include<functional>
#include<map>
#include<cmath>
#include "test14_6_Sales_data.h"
#include "test14_7_String.h"

using namespace std;


//test 14.34
class FuncObject {
public:
    int operator()(bool, int, int);
};

int FuncObject::operator() (bool v1, int v2, int v3) {
    if(v1) {
        return v2;
    } else {
        return v3;
    }
}

//test 14.35 14.36
class ReadString {
public:
    ReadString(istream &i = cin) : is(i) {}
    string operator()() {
        string s;
        getline(is, s);
        if(is) {
            return s;
        } else {
            return "";
        }
    }
private:
    istream &is;
};

//test 14.37
class IsEqual {
public:
    IsEqual(const int val) : target(val) {}
    bool operator()(const int val) {
        return target == val;
    }
private:
    int target;
};

//test 14.38
class LengthEqualTo {
public:
    LengthEqualTo(const int val) : target(val) {}

    bool operator()(const string& s) {return s.size() == target;}
private:
    size_t target;
};

//test 14.52 definition of SmallInt
struct SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int i = 0) : val(i) {
        cout << "SmallInt(int) is called" << endl;
    }
    operator int() const {
        cout << "operator int() const is called" << endl;
        return val;
    }

    std::size_t get_val() const { return val;}
private:
    std::size_t val;
};

SmallInt operator+(const SmallInt &s1, const SmallInt &s2) {
    cout << "SmallInt operator+(const SmallInt&, const SmallInt&) is called" << endl;
    return s1.val + s2.val;
}

//test 14.50 14.52
struct LongDouble {

friend LongDouble operator+(LongDouble&, double);
public:
    LongDouble(double d = 0.0) : val(d) {
        cout << "LongDouble(double) is called" << endl;
    }
    operator double() {
        cout << "operator double() is called" << endl;
        return val;
    }

    operator float() {
        cout << "operator float() is called" << endl;
        return float(val);
    }

    LongDouble operator+(const SmallInt &si) {
        cout << "LongDouble operator+(const SmallInt&) is called" << endl;
        return val + si.get_val();
    }

private:
    double val = 0.0;
};

//test 14.52
LongDouble operator+(LongDouble &ld, double d) {
    cout << "non member operator+(LongDouble&, double) is called" << endl;
    return ld.val + d;
}

//test 14.51
void calc(int x) {
    cout << "calc(int) is called" << endl;
}

void calc(LongDouble ld) {
    cout << "calc(LongDouble) is called" << endl;
}

int main() {
//    string s = "dobble";
//    cout << (s == "dobble") << endl;
//    cout << ("dobble" == "stone");

//test 14.2 14.6 14.9  14.13 14.20 14.22
//test Sales_data:  >>, <<, ==, +, -
//    Sales_data item1;
//    Sales_data item2;
//    cin >> item1;
//    cin >> item2;
//    cout << item1 << endl;
//    cout << item2 << endl;
//    cout << (item1 == item2) << endl;
//    Sales_data sum = item1 + item2;
//    cout << sum << endl;
//    Sales_data remain = item1 - item2;
//    cout << remain << endl;
//    //test new operator=, test 14.22
//    string s = "book2";
//    item1 = s;
//    cout << item1 << endl;

//test 14.7 14.16 14.18 14.26
//    String s1("hello");
//    String s2("world");
//    String s3 = "hello";
//    cout << s1 << endl;
//    cout << s2 << endl;
//    cout << (s1 == s3) << endl;
//    cout << (s1 < s3) << endl;
//    cout << (s1 < s2) << endl;
//    for(size_t i = 0; i != s1.size(); ++ i) {
//        cout << s1[i];
//    }
//    cout << endl;
//    for(size_t i = 0; i != s2.size(); ++ i) {
//        s2[i] = toupper(s2[i]);//#include<cctype>
//    }
//    cout << s2 << endl;

//test 14.34
//    FuncObject if_then_else;
//    cout << if_then_else(false, 1, 2) << endl;
//    cout << if_then_else(true, 1, 2) << endl;

//test 14.35
//    ReadString read_string;
//    cout << read_string() << endl;

//test 14.36
//    vector<string> vs;
//    string s;
//    ReadString read_string;
//    while(!(s = read_string()).empty()) {
//        vs.push_back(s);
//    }
//    cout << vs.size() << endl;
//    for(string &s : vs) {
//        cout << s << endl;
//    }

//test 14.37
//if equals to 1, then replace it with 2.
//    vector<int> vi = {1, 2, 1, 2, 1, 2};
//    IsEqual is_equal(1);
//    replace_if(vi.begin(), vi.end(), is_equal, 2);//#include<algorithm>
//    for_each(vi.begin(), vi.end(), [] (const int &i) { cout << i << ends;});

//test 14.38
//    for(int i = 1; i != 11; ++ i) {
//        ifstream input("test14_38_39.txt");//#include<fstream>
//        istream_iterator<string> str_itr(input);//#Include<iterator>
//        istream_iterator<string> eof;
//        cout << count_if(str_itr, eof, LengthEqualTo(i)) << " words length equal to " << i << endl;
//    }

//test 14.42
//    //(a)
//    vector<int> vi = {4, 64, 256, 2048, 4096, 8192};
//    cout << count_if(vi.begin(), vi.end(), bind(greater<int>(), std::placeholders::_1, 1024)) << " numbers larger than 1024." << endl;
//
//    //(b)
//    vector<string> vs = {"pooh", "pooh", "love"};
//    auto iter = find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), std::placeholders::_1, "pooh"));
//    cout << (iter - vs.cbegin()) << "th words not equal to pooh" << endl;
//    //(c)
//    vector<int> vi2 = {1, 3, 5, 7, 9};
//    transform(vi2.begin(), vi2.end(), vi2.begin(), bind(multiplies<int>(), std::placeholders::_1, 2));
//    for_each(vi2.begin(), vi2.end(), [](const int &i) { cout << i << ends; });
//    cout << endl;

//test 14.43
//    vector<int> vi = {3, 6, 12, 18, 24};
//    int val = 3;
//    auto res = any_of(vi.cbegin(), vi.cend(), bind(modulus<int>(), std::placeholders::_1, val));
//    if(res) {
//        cout << "Not all elements in vector can be divided by " << val << endl;
//    } else {
//        cout << "All elements in vector can be divided by " << val << endl;
//    }

//test 14.44 simple caculator
//    map<string, function<double(double,double)>> binops;
//    binops.insert({"+", plus<double>()});
//    binops.insert({"-", minus<double>()});
//    binops.insert({"*", multiplies<double>()});
//    binops.insert({"/", [](double i, double j) {return (j == 0.0) ? 1000000 : i / j;}});
//    binops.insert({"^", [](double i, double j) {return pow(i, j);}});//#include<cmath>
//    double i, j;
//    string s;
//    while(true) {
//        cin >> i >> s >> j;
//        if(!cin) {
//            break;
//        }
//        cout << i << s << j << " = " << binops[s](i, j) << endl;
//    }


//test 14.50 14.51
//    LongDouble ldObj;
////    int ex1 = ldObj;//ambiguous
//    float ex2 = ldObj;//call float()
//    double dval = 5;
//    calc(dval);// call calc(int)
////    calc(LongDouble(dval));// call calc(LongDouble)
//    int ival = 4;
//    calc(ival);

//test 14.52
    SmallInt si;
    LongDouble ld;
//    ld = si + ld;//ambiguous, 2 candidates
    ld = ld + si;//call member operator+

//test 14.53
//    SmallInt s1;
//    double d = s1 + 3.14;//ambiguous

    return 0;
}

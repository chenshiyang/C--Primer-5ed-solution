#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<numeric>
#include<iterator>
#include<functional>
#include<fstream>

using namespace std;
using namespace std::placeholders;

//test sort() and unique()
void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    for(auto s : words) {
        cout << s << ends;
    }
    cout << endl;
    auto end_unique = unique(words.begin(), words.end());
        for(auto s : words) {
        cout << s << ends;
    }
    cout << endl;
    words.erase(end_unique, words.end());
        for(auto s : words) {
        cout << s << ends;
    }
    cout << endl;
}

//test 10.11
bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

//test 10.13
bool isMoreThanFive(const string &s) {
    return s.size() >= 5;
}

//test 10.14  get sum
int getSum(const int &i1, const int &i2) {
    auto f = [i1, i2] () -> const int {return i1 + i2;};
    return f();
}

//test 10.15
int getSum2(const int &i) {
    auto f = [i] (const int &j) -> const int {return i + j;};
    return f(2);
}

//test 10.20 count longer than 6
int count_longer_than_six(const vector<string> &svec) {
    return count_if(svec.cbegin(), svec.cend(), [](const string &s) -> bool {return s.size() >= 6;});
}

//test 10.21 decrease an int varible
bool decrease_variable(int i) {
    auto f = [&]() -> bool {
        while(i > 0) {
            -- i;
        }
        return true;
    };
    return f();
}

//test 10.24
void get_first_longer_than(const string &s1, const string &s2) {
    if(s2.size() >= s1.size()) {
        cout << s2 << endl;
    }
}

int main() {
    //test find()
//    vector<int> ivec = {1, 3, 2, 4, 5, 7};
//    int val = 7;
//    auto result = find(ivec.begin(), ivec.end(), val);
//    cout << "The value " << val << (result == ivec.end()? " is not present" : " is present") << endl;
//
//    vector<string> svec = {"I", "am", "a", "hero"};
//    auto result2 = find(svec.begin(), svec.end(), "a");
//        cout << "The value " << "a" << (result2 == svec.end()? " is not present" : " is present") << endl;

    //test 10.1
//    vector<int> ivec = {1, 2, 3, 3, 4, 2, 1, 3};
//    int val = 3;
//    cout << "The count of " << val << " is " << count(ivec.begin(), ivec.end(), val) << endl;
//    //test 10.2
//    list<string> slst = {"I", "am", "a", "hero"};
//    string sval = "hero";
//        cout << "The count of " << sval << " is " << count(slst.begin(), slst.end(), sval) << endl;


//test accumulate()
//    vector<string> svec = {"I", "am", "a", "hero"};
//    string sum = "";
//    sum = accumulate(svec.begin(), svec.end(), sum);
//    cout << sum << endl;
//
//    vector<int> ivec = {1, 2, 3, 4};
//    int isum = 0;
//    isum = accumulate(ivec.begin(), ivec.end() - 1, isum);
//    cout << isum << endl;

//test 10.4
//    vector<double> dvec = {0.1, 1.1, 2.1, 3.1};
//    double sum = accumulate(dvec.begin(), dvec.end(), 0.0);
//    cout << sum << endl;

//test 10.5
//    list<const char*> lst1 = {"I\0", "am\0", "a\0", "hero\0"};
//    list<const char*> lst2 = {"I\0", "am\0", "a\0"};
//    cout << equal(lst1.cbegin(), lst1.cend(), lst2.cbegin());

//    list<int> ilst1 = {1, 2, 3};
//    list<int> ilst2 = {1, 2, 3};
//    cout << equal(ilst1.cbegin(), ilst1.cend(), ilst2.cbegin()) << endl;

//test back_inserter
//    vector<int> vec;
//    fill_n(back_inserter(vec), 10, 0);
//    for(auto i : vec) {
//        cout << i << ends;
//    }

//test 10.6
//    list<int> ilst = {1, 2, 3, 4, 5, 6, 7};
//    fill_n(ilst.begin(), ilst.size(), 0);
//    for(auto i : ilst) {
//        cout << i << ends;
//    }

//test 10.7

//(a)
//    vector<int> vec;
//    list<int> lst;
//    int i;
//    while(cin >> i) {
//        lst.push_back(i);
//    }
//    copy(lst.cbegin(), lst.cend(), back_inserter(vec));
//    for(auto i : vec) {
//        cout << i << ends;
//    }
//(b)
//    vector<int> vec;
//    vec.reserve(10);
//    cout << vec.size() << endl;//0
//    cout << vec.capacity() << endl;//10
//    fill_n(vec.begin(), 10, 0);
//    cout << vec.size() << endl;//0
//    for(auto i : vec) {
//        cout << i << ends;
//    }

//test sort() and unique() p343
//    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
//    elimDups(words);

//test 10.11
//    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
//    elimDups(words);
//    stable_sort(words.begin(), words.end(), isShorter);
//    for(const auto &s : words) {
//        cout << s << ends;
//    }

//test 10.13
//    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
//    auto it_end = partition(words.begin(), words.end(), isMoreThanFive);
//    for(auto itr = words.begin(); itr != it_end; ++ itr) {
//        cout << *itr << ends;
//    }
//    cout << endl;

//test 10.14
//    cout << getSum(1, 2) << endl;

//test 10.15
//    cout << getSum2(1) << endl;

//test 10.20
//    vector<string> svec = {"that", "I", "would", "change", "my", "on", "the", "range"};
//    cout << count_longer_than_six(svec) << endl;

//test 10.21
//    int i = 10;
//    cout << decrease_variable(i) << endl;

//test 10.24
//    vector<string> svec = {"I", "am", "a", "hero"};
//    string s = "two";
//    for_each(svec.begin(), svec.end(), bind(get_first_longer_than, ref(s), _1));

//test 10.27
//    vector<int> ivec = {1, 2, 2, 3, 4, 5, 4};
//    sort(ivec.begin(), ivec.end(), [](const int &i1, const int &i2) {return i1 < i2;});
//    list<int> ilst1;
//    list<int> ilst2;
//    list<int> ilst3;
//    unique_copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst1));
//    unique_copy(ivec.cbegin(), ivec.cend(), inserter(ilst2, ilst2.begin()));
//    unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst3
//
//                                                          ));
//
//    for(auto i : ilst1) {
//        cout << i << ends;
//    }
//    cout << endl;
//    for(auto i : ilst2) {
//        cout << i << ends;
//    }
//    cout << endl;
//    for(auto i : ilst3) {
//        cout << i << ends;
//    }
//    cout << endl;

//test istream_iterator p360
//    istream_iterator<int> in(cin), eof;
//    cout << accumulate(in, eof, 0) << endl;

//test ostream_iterator p361
//    ostream_iterator<int> out_iter(cout, " ");
//    vector<int> vec = {1, 2, 3, 4, 5};
//    copy(vec.begin(), vec.end(), out_iter);
//    cout << endl;

//test 10.29
//    ifstream in("test10.29.txt");
//    istream_iterator<string> in_itr(in), eof;
//    vector<string> svec(in_itr, eof);//use iterator to initialize vector.
//    for(string s : svec) {
//        cout << s << ends;
//    }
//    cout << endl;

//test 10.30
//    istream_iterator<int> in_itr(cin), eof;
//    vector<int> ivec(in_itr, eof);
//    sort(ivec.begin(), ivec.end(), [](const int &i1, const int &i2) {return i1 < i2;});
//    ostream_iterator<int> out_itr(cout, " ");
//    copy(ivec.begin(), ivec.end(), out_itr);
//    cout << endl;

//test 10.31
//    istream_iterator<int> in_itr(cin), eof;
//    vector<int> ivec(in_itr, eof);
//    sort(ivec.begin(), ivec.end(), [](const int &i1, const int &i2) {return i1 < i2;});
//    ostream_iterator<int> out_itr(cout, " ");
//    unique_copy(ivec.begin(), ivec.end(), out_itr);
//    cout << endl;

//test 10.33
//    ifstream in("test10.33in.txt");
//    ofstream out1("test10.33out1.txt"), out2("test10.33out2.txt");
//    istream_iterator<int> in_itr(in), eof;
//    ostream_iterator<int> out_itr1(out1, " "), out_itr2(out2, " ");
//    while(in_itr != eof) {
//        if(*in_itr % 2 == 0) {
//            out_itr2 = *in_itr ++;
//        } else {
//            out_itr1 = *in_itr ++;
//        }
//    }

//test reverse iterator p364
//    string line("FIRST,MIDDLE,LAST");
//    auto comma = find(line.cbegin(), line.cend(), ',');
//    cout << string(line.cbegin(), comma) << endl;
//
//    auto rcomma = find(line.crbegin(), line.crend(), ',');
//    cout << string(line.crbegin(), rcomma) << endl;
//    cout << string(rcomma.base(), line.cend()) << endl;

//test 10.34
//    vector<string> svec = {"I", "am", "a", "hero"};
//    for(auto itr = svec.crbegin(); itr != svec.crend(); ++ itr) {
////        cout << *itr << ends;
//        for(auto sitr = (*itr).crbegin(); sitr != itr->crend(); ++ sitr) {
//            cout << *sitr;
//        }
//        cout << ends;
//    }
//    cout << endl;

//test 10.35
//    vector<string> svec = {"I", "am", "a", "hero"};
//    for(auto itr = svec.cend() - 1; itr != svec.cbegin() - 1; -- itr) {
//        cout << *itr << ends;
//    }

//test 10.36
//    list<int> lst = {1, 2, 3, 0, 6, 0, 1};
//    auto rzero = find(lst.crbegin(), lst.crend(), 0);
//    if(rzero != lst.crend()) {
//        cout << *rzero << endl;
//    } else {
//        cout << "no element equals to 0" << endl;
//    }


//test 10.37
////solution1 front_inserter
//    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    list<int> lst;
//    copy(ivec.cbegin() + 3, ivec.cbegin() + 8, front_inserter(lst));
//    for(auto i : lst) {
//        cout << i << ends;
//    }
////solution2 back_inserter

//test remove_copy_if p369
//    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
//    vector<int> v2;
//    remove_copy_if(v1.cbegin(), v1.cend(), back_inserter(v2),
//                   [](int i) {return i % 2;});
//    for(int i : v1) {
//        cout << i << ends;
//    }
//    cout << endl;
//    for(int i : v2) {
//        cout << i << ends;
//    }

//test 10.42
//    list<string> slst = {"b", "a", "c", "b", "f", "a", "d", "e", "e"};
//    slst.sort();
//    slst.unique();
//    for(auto s : slst) {
//        cout << s << ends;
//    }

    return 0;
}

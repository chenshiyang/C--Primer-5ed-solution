#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<iterator>
#include<fstream>
#include<sstream>

using namespace std;

//test 11.7
//void add_family(map<string, vector<string>> &families, const vector<string> &family, string &surname) {
//    if(families.find(surname) == families.end()) {
//        families[surname] = family;
//    } else {
//        auto &f = families[surname];
////        f.insert(f.begin(), family.cbegin(), family.cend());
//        for(auto &ff : family) {
//            f.push_back(ff);
//        }
//    }
//}

//test 11.33 p392 letter converter
map<string, string> buildMap(ifstream &map_file) {
    map<string, string> rule_map;
    string key;
    string value;
    string line;
    while(getline(map_file, line)) {
        auto space = line.find(string(" "));
        if(space == string::npos || space + 1 == line.size()) {
            throw runtime_error("invalid rule for" + line);
        }
        key = line.substr(0, space);
        value = line.substr(space + 1);
        rule_map[key] = value;
    }
    return rule_map;
}

//test 11.33 p392 letter converter
const string &transform(const string &s, const map<string, string> &map) {
    auto itr = map.find(s);
    if(itr == map.cend()) {
        return s;
    }
    return itr->second;
}


//test 11.33 p392 letter converter
void word_transform(ifstream &map_file, ifstream &input) {
    map<string, string> rule_map = buildMap(map_file);
    string line;
    while(getline(input, line)) {
        istringstream stream(line);
        string word;
        bool firstword = true;
        while(stream >> word) {
            if(firstword) {
                firstword = false;
            } else {
                cout << " ";
            }
            cout << transform(word, rule_map);
        }
        cout << endl;
    }
}

int main() {
//test p375
//    map<string, size_t> word_count;
//    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
//    string word;
//    while(cin >> word) {
//        if(exclude.find(word) == exclude.end()) {
//        ++word_count[word];
//        }
//    }
//    for(const auto &w : word_count) {
//        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
//    }


//test 11.7
//    map<string, vector<string>> families;
//    string line;
//    while(getline(cin, line)) {
//        auto pos = line.find(' ', 0);
//        string surname = line.substr(0, pos);
//        vector<string> family;
//        while(pos != string::npos) {
//            int bg = pos;
//            pos = line.find(' ', bg + 1);
//            if(pos == string::npos) {
//                family.push_back(line.substr(bg + 1, line.size()));
//            } else {
//                family.push_back(line.substr(bg + 1, pos - bg - 1));
//            }
//        }
//        add_family(families, family, surname);
//    }
//    for(const auto &pr : families) {
//        cout << pr.first << ":" << ends;
//        for(const auto &s : pr.second) {
//            cout << s << ",";
//        }
//        cout << endl;
//    }


//test 11.16
//    map<int, int> imap = {{1, 2}};
//    auto map_itr = imap.begin();
//    map_itr->second = -1;
////    (*map_itr).second = 1;
//    for(auto pr : imap) {
//        cout << pr.first << " " << pr.second << endl;
//    }

//test 11.17
//    vector<string> v = {"a", "b", "c"};
//    multiset<string> c = {"c", "d", "e"};
//
////    copy(v.begin(), v.end(), inserter(c, c.end()));
////    copy(v.begin(), v.end(), back_inserter(c));
////    copy(c.begin(), c.end(), inserter(v, v.end()));
//    copy(c.begin(), c.end(), back_inserter(v));
//    for(auto cc : c) {
//        cout << cc << ends;
//    }
//    cout << endl;
//    for(auto i : v) {
//        cout << i << ends;
//    }

//test 11.20
//    map<string, size_t> word_count;
//    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
//    string word;
//    while(cin >> word) {
//        if(exclude.find(word) == exclude.end()) {
////            auto ret = word_count.insert({word, 1});
////            if(!ret.second) {
////                ++ ret.first->second;
////            }
//            ++ word_count.insert({word, 0}).first->second;
//        }
//    }
//    for(const auto &w : word_count) {
//        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
//    }

//test 11.23
//    multimap<string, string> mmap;
//    string line;
//    while(getline(cin, line)) {
//        auto pos = line.find(' ', 0);
//        string surname = line.substr(0, pos);
//        mmap.insert({surname, line.substr(pos + 1, line.size())});
//    }
//    for(auto itr = mmap.cbegin(); itr != mmap.end(); ++ itr ) {
//        cout << itr->first << " " << itr->second << endl;
//    }

//test equal_range() p389
//    map<char, int> mymap;
////    mymap['a'] = 10;
//    mymap['b'] = 20;
//    mymap['c'] = 30;
//    auto ret = mymap.equal_range('b');
//
//    cout << "lower bound points to" << ends;
//    cout << ret.first->first << " => " << ret.first->second << endl;
//    cout << "upper bound points to" << ends;
//    cout << ret.second->first << " => " << ret.second->second << endl;

//test lower_bound and upper_bound p390
//    map<int, int> imap;
//    imap[1] = 1;
//    imap[2] = 2;
//    imap[3] = 3;
//    auto lower = imap.lower_bound(3);
//    auto upper = imap.upper_bound(3);
//    if(lower == upper) {
//        cout << "3 is not in map" << endl;
//    } else {
//        cout << "3 is in map" << endl;
//    }

//test 11.28
//    vector<string> svec = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
//    map<string, vector<string>> mymap;
//    mymap[string("week")] = svec;
//    auto itr = mymap.find(string("week"));
//    while(itr != mymap.end()) {
//        auto vec = itr->second;
//        for(auto s : vec) {
//            cout << s << endl;
//        }
//        ++ itr;
//    }

//test 11.31
//    multimap<char, char> mymap;
//    mymap.insert({'a', 'A'});
//    mymap.insert({'a', '1'});
//    mymap.insert({'b', 'B'});
//    mymap.insert({'b', '2'});
//    char target = 'a';
//
//    while(mymap.lower_bound(target) != mymap.upper_bound(target)) {
//        auto itr = mymap.find(target);
//        mymap.erase(itr);
//    }
//    for(auto bg = mymap.cbegin(); bg != mymap.cend(); ++ bg) {
//        cout << bg->first << " " << bg->second << endl;
//    }

//test 11.33 p392 letter converter
//    ifstream map_file("map_file.txt");
//    ifstream input("input.txt");
//    word_transform(map_file, input);

    return 0;
}

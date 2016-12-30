#ifndef TEST19_20_QUERY_H
#define TEST19_20_QUERY_H
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<memory>
#include<sstream>



using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::set;
using std::map;
using std::shared_ptr;
using std::make_shared;
using std::istringstream;
using std::ostream;
using std::out_of_range;


class TextQuery {
public:
    class QueryResult;
    TextQuery() {}
    TextQuery(ifstream&);

    QueryResult query(const string&);
private:
    shared_ptr<vector<string>> lines;
    shared_ptr<map<string, set<int>>> word_occur;
};

class TextQuery::QueryResult {
public:
    QueryResult() {}
    QueryResult(TextQuery&, const string&);
    const string& get_word() { return word;}
    const shared_ptr<map<string, set<int>>>& get_word_occur(){ return word_occur;}
    const shared_ptr<vector<string>>& get_lines() { return lines; }
private:
    string word;
    shared_ptr<vector<string>> lines;
    shared_ptr<map<string, set<int>>> word_occur;
};

TextQuery::QueryResult::QueryResult(TextQuery &tq, const string &s) {
    lines = tq.lines;
    word_occur = tq.word_occur;
    word = s;
}

TextQuery::TextQuery(ifstream& in_file) {
    string line;
    int line_number = 1;
    lines = make_shared<vector<string>>();
    word_occur = make_shared<map<string, set<int>>>();
    while(getline(in_file, line)) {
        lines->push_back(line);
        istringstream words(line);
        string word;
        while(words >> word) {
            (*word_occur)[word].insert(line_number);
        }
        ++ line_number;
    }
}

TextQuery::QueryResult TextQuery::query(const string &s) {
    QueryResult rq(*this, s);
    return rq;
}

void print(ostream &out, TextQuery::QueryResult qr) {//QueryResult qr can not use reference
    try {
        auto sets = qr.get_word_occur()->at(qr.get_word());
        out << qr.get_word() << " occurs " << sets.size() << " times" << endl;
        for(auto i : sets) {
            out << "(line " << i << ")" << (*(qr.get_lines()))[i - 1] << endl;//line number start from 1.
        }
    } catch(out_of_range oor) {
        out << "the word is not exist" << endl;
    }
}

void runQueries(ifstream &in_file) {
    TextQuery tq(in_file);
    while(true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s));
    }
}

#endif // TEST19_20_QUERY_H

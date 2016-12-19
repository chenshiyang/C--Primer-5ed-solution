#ifndef TEST15_QUERY_BASE_H
#define TEST15_QUERY_BASE_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
#include <iterator>
#include <map>
#include <algorithm>

using std::vector;
using std::ifstream;
using std::string;
using std::shared_ptr;
using std::set;
using std::istringstream;
using std::ostream;
using std::iterator;
using std::map;
using std::endl;
using std::make_shared;
using std::inserter;
using std::set_intersection;
using std::ifstream;
using std::cout;
using std::cin;

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file;
    //A reflection of : word -> the set of words line no.
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream& is) : file(new vector<string>) {
    string text;
    while(getline(is, text)) {
        file -> push_back(text);
        int n = file -> size() - 1;//current line no
        istringstream line(text);
        string word;
        while(line >> word) {
            auto &lines = wm[word];
            if(!lines) {//if word not exists in wm
                lines.reset(new set<line_no>);
            }
            lines -> insert(n);//add current line no.
        }
    }
}

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
    using line_no = vector<string>::size_type;
public:
    QueryResult(string s, shared_ptr<set<line_no>> p,  shared_ptr<vector<string>> f) :
        sought(s), lines(p), file(f) { }

    shared_ptr<vector<string>> get_file() const { return file; }

    set<line_no>::iterator begin() {
        return (*lines).begin();
    }

    set<line_no>::iterator end() {
        return (*lines).end();
    }

    shared_ptr<set<line_no>> get_lines() const { return lines; }

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end()) {//if not find
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc -> second, file);
    }
}

ostream& print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines -> size() << " "
    << "times" << endl;
    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
        << *(qr.file -> begin() + num) << endl;
    }
    return os;
}

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;

    virtual ~Query_base() = default;

private:
    //pure virtual function
    virtual QueryResult eval(const TextQuery&) const = 0;
    //pure virtual function
    virtual string rep() const = 0;
};

class Query {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string&);

    QueryResult eval(const TextQuery &t) const {
        return q -> eval(t);
    }

    string rep() const { return q -> rep(); }

private:
    Query(shared_ptr<Query_base> query) : q(query) { }

    shared_ptr<Query_base> q;
};

ostream& operator<<(ostream &os, const Query &query) {
    return os << query.rep();
}

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const string &s) : query_word(s) { }
    QueryResult eval(const TextQuery &t) const {
        return t.query(query_word);
    }
    string rep() const { return query_word; }
    string query_word;
};

inline Query::Query(const string &s) : q(new WordQuery(s)) { }

class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q) : query(q) { }

    string rep() const { return "~(" + query.rep() + ")"; };
    QueryResult eval(const TextQuery &t) const;

    Query query;
};

inline Query operator~(const Query &operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s) :
    lhs(l), rhs(r), opsSym(s) { }

    string rep() const {
        return "(" + lhs.rep() +  " " + opsSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;//left and right operands
    string opsSym;//operator name
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &l, const Query &r) :
        BinaryQuery(l, r, "&") { }

    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &l, const Query &r) :
        BinaryQuery(l, r, "|") { }

    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());

    ret_lines -> insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();

    set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));//#include <algorithm>
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file() -> size();

    for(size_t n = 0; n != sz; ++ n) {
        if(beg == end || *beg != n) {
            ret_lines -> insert(n);
        } else if(beg != end) {//*beg == n
            ++ beg;
        }
    }

//    auto &lines = result.get_lines();
//    for(size_t n = 0; n != sz; ++ n) {
//        if(lines -> find(n) != lines -> end()) {
//            ret_lines -> insert(n);
//        }
//    }

    return QueryResult(rep(), ret_lines, result.get_file());
}

//void runQueries(ifstream &in_file) {
//    TextQuery tq(in_file);
//    while(true) {
//        cout << "Enter word to look for, or q to quit: ";
//        string s;
//        if(!(getline(cin, s)) || s == "q") {
//            break;
//        }
//        istringstream ss(s);
//        string word;
//        bool no = 0;
//        bool ad = 0;
//        bool o = 0;
//        Query left(" ");
//        while(ss >> word) {
//            if(word == "~") {
//                no = !no;
//            } else if(word == "&") {
//                ad = true;
//            } else if(word == "|") {
//                o = true;
//            }
//        }
//        print(cout, tq.query(s));
//    }
//}

#endif // TEST15_QUERY_BASE_H

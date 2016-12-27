#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

map<string, vector<string>> build_map(ifstream &map_file) {
    map<string, vector<string>> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value)) {
        if(value.size() > 1) {
            trans_map[key].push_back(value.substr(1));
        } else {
            throw runtime_error("no rulue for " + key);
        }
    }
    return trans_map;
}

const string& transform(const string &s, const map<string, vector<string>> &m) {
    auto svec = m.find(s);
    if(svec != m.cend()) {
        static default_random_engine e;
        uniform_int_distribution<unsigned> u(0, svec -> second.size() - 1);
        unsigned i = u(e);
        return svec -> second[i];
    } else {
        return s;
    }
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = build_map(map_file);
    string text;
    while(getline(input, text)) {
        istringstream stream(text);
        string word;
        bool first_word = true;
        while(stream >> word) {
            if(first_word) {
                first_word = false;
            } else {
                cout << " ";
                cout << transform(word, trans_map);
            }
        }
        cout << endl;
    }
}

int main() {
    string map_path("test17_33_map.txt");
    ifstream map_file(map_path);
    string input_path("test17_33_input.txt");
    ifstream input_file(input_path);
    word_transform(map_file, input_file);
    return 0;
}

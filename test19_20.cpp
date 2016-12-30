#include <iostream>
#include <string>
#include <fstream>
#include "test19_20_Query.h"

using namespace std;

int main() {
    string path("test12text.txt");
    ifstream in_file(path);
    runQueries(in_file);
    return 0;
}

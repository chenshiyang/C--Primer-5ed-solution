#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
using namespace std;

int main() {
    string path("test17_37.txt");
    ifstream is(path);
	char sink[80] = {'\0'};
	size_t size = 80;
	char delim = '\n';
	while(is.getline(sink, size, delim)) {
		cout.write(sink, size);
		cout << "\n";
		memset(sink, '\0', size);
	}
	return 0;
}

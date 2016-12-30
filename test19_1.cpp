#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

void* operator new (size_t size) {
    cout << "operator new(" << size << ")" << endl;
    if(void *mem = malloc(size)) {
        return mem;
    } else {
        throw bad_alloc();
    }
}

void operator delete(void *mem) noexcept {
    cout << "operator delete(" << mem << ")" << endl;
    free(mem);
}

class Test {
private:
    int i;
    long l;
};

int main() {
    int *pi = new int(1);
    delete pi;
    long *pl = new long(10);
    delete pl;
    Test *pt = new Test();
    delete pt;
    return 0;
}

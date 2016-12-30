#ifndef TEST13_39_STRVEC_H
#define TEST13_39_STRVEC_H

#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <initializer_list>
#include <new>


using namespace std;

class StrVec {

public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>&);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }

    void reserve(size_t);
    void resize(size_t);
    void resize(size_t, const string&);

private:

    static allocator<string> alloc;
    void chk_n_alloc() {
        if(size() == capacity()) {
            reallocate();
        }
    }

    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    void add_rem(size_t n, const string &s = "");

    string *elements;
    string *first_free;
    string *cap;
};
allocator<string> StrVec::alloc;

StrVec::StrVec(initializer_list<string> &il) {
    auto new_data = alloc_n_copy(il.begin(), il.end());
    elements = new_data.first;
    first_free = new_data.second;
    cap = new_data.second;
}

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free ++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *bg, const string *ed) {
    auto data = alloc.allocate(ed - bg);
    return {data, uninitialized_copy(bg, ed, data)};
}

void StrVec::free() {
    if(elements) {
        for(auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
//        for_each(begin(), end(), [](const string &s) { alloc.destroy(&s);});

        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = new_data.second;
    cap = new_data.second;
}

StrVec& StrVec::operator=(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

StrVec::~StrVec() { free(); }

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++ i) {
        alloc.construct(dest ++, std::move(*elem ++));
    }
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void StrVec::reserve(size_t n) {
    if(n > capacity()) {
        auto newdata = alloc.allocate(n);
        auto dest = newdata;
        auto elem = elements;
        for(size_t i = 0; i != size(); ++ i) {
            alloc.construct(dest ++, move(*elem ++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = newdata + n;
    }//else do nothing
}

void StrVec::resize(size_t n)
{
	add_rem(n);
}

void StrVec::resize(size_t n, const string &s)
{
	add_rem(n, s);
}

void StrVec::add_rem(std::size_t n, const string &s)
{
	if(n <= size()) {
		auto p = first_free;
		while(p != elements + n)
			alloc.destroy(--p);
		first_free = p;
	}
	else{
		auto new_elem_count = n - size();
		for(std::size_t i = 0; i != new_elem_count; ++i)
			push_back(s);
	}
}


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

#endif // TEST13_39_STRVEC_H


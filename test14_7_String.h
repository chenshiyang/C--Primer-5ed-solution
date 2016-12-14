#ifndef TEST14_7_STRING_H
#define TEST14_7_STRING_H

#include <iostream>
#include <memory>
#include <string>
#include <cstring>

using std::ostream;
using std::size_t;
using std::allocator;
using std::pair;

class String {
friend ostream& operator<<(ostream&, const String&);

//overload == , test 14.16
friend bool operator==(const String&, const String&);
//overload != , test 14.16
friend bool operator!=(const String&, const String&);
//overload < , test 14.18
friend bool operator<(const String&, const String&);

public:
    String();
    String(const char*);
    String(const String&);
    String(String&&) noexcept;//move constructor

    ~String();

    String& operator=(const String&);//copy assignment
    String& operator=(String&&) noexcept;//move assignment

    //test 14.26
    char& operator[](size_t);
    const char& operator[](size_t) const;

    void push_back(const char&);
    void push_back(char&&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    char* begin() const {return elements;}
    char* end() const {return first_free;}
    bool empty() const {return elements == first_free;}
    //reset all chars in this String.
    void clear();
private:

    void chk_n_alloc() {if(size() == capacity()) reallocate();}
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    void reallocate();

    static allocator<char> alloc;
    const static size_t ini_size = 15;
    char *elements;
    char *first_free;
    char * cap;
};

allocator<char> String::alloc;

ostream& operator<<(ostream &os, const String &s) {
    for(auto p = s.begin(); p != s.end(); ++ p) {
        os << *p;
    }
    return os;
}

bool operator==(const String &s1, const String &s2) {
    if(s1.size() != s2.size()) {
        return false;
    } else {
        for(auto p = s1.begin(), q = s2.begin(); p != s1.end(); ++ p, ++ q) {
            if(*p != *q) {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const String &s1, const String &s2) {
    return !(s1 == s2);
}

bool operator<(const String &s1, const String &s2) {
    auto shorter = s1.size() < s2.size() ? s1.size() : s2.size();
    auto p = s1.begin(), q = s2.begin();
    for(size_t i = 0; i != shorter; ++ i) {
        if(*(p + i) == *(q + i)) {
            continue;
        } else if(*(p + i) < *(q + i)){
            return true;
        } else {
            return false;
        }
    }
    return s1.size() < s2.size();
}

String::String() : elements(nullptr), first_free(nullptr), cap(nullptr) {
    elements = alloc.allocate(ini_size);
    first_free = elements;
    cap = elements + ini_size;
}

String::String(const char *s) {
    auto new_data = alloc_n_copy(s, s + strlen(s));
    elements = new_data.first;
    first_free = new_data.second;
    cap = (strlen(s) > ini_size) ? first_free : (elements + ini_size);
}

//move constructor
String::String(String&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap){
    s.elements = s.first_free = s.cap = nullptr;
    std::cout << "String(String&&) is called" << std::endl;
}

String& String::operator=(const String& s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = new_data.first;
    first_free = new_data.second;
    cap = (s.size() > ini_size) ? first_free : (elements + ini_size);
    std::cout << "String& operator=(const String&) is called" << std::endl;
    return *this;
}

String& String::operator=(String &&s) noexcept {
    if(this != &s) {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    std::cout << "String& operator=(String&&) is called" << std::endl;
    return *this;
}

char& String::operator[](size_t n) {
    return elements[n];
}

const char& String::operator[](size_t n) const {
    return elements[n];
}

String::~String() {
    free();
}

void String::push_back(const char &c) {
    chk_n_alloc();
    alloc.construct(first_free ++, c);
}

void String::push_back(char &&c) {
    chk_n_alloc();
    alloc.construct(first_free ++, std::move(c));
}

void String::clear() {
    for(auto p = first_free; p != elements;) {
        alloc.destroy( -- p);
    }
    first_free = elements;
}

pair<char*, char*> String::alloc_n_copy(const char* bg, const char* ed) {
    auto new_capacity = (ed - bg > ini_size) ? (ed - bg) : ini_size;
    auto new_data = alloc.allocate(new_capacity);
    return {new_data, std::uninitialized_copy(bg, ed, new_data)};
}

void String::reallocate() {
    auto new_capacity = (size() * 2 > ini_size) ? size() * 2 : ini_size;
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++ i) {
        alloc.construct(dest ++, std::move(*elem ++));
    }
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void String::free() {
    for(auto p = first_free; p != elements;) {
        alloc.destroy(-- p);
    }
    alloc.deallocate(elements, cap - elements);
}




#endif // TEST14_7_STRING_H

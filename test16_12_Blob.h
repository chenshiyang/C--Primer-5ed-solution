#ifndef TEST16_12_BLOB_H
#define TEST16_12_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using std::vector;
using std::string;
using std::initializer_list;

template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);


template <typename T> class Blob {
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator><T>(const Blob<T>&, const Blob<T>&);
    friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    //constructors
    Blob();
    Blob(std::initializer_list<T> il);
    //template constructor, required by test 16.24
    template <typename It>
    Blob(It, It);

    size_type size() const { return data -> size(); }

    bool empty() const { return data -> empty(); }

    void push_back(const T &t) { data -> push_back(t); }

    void push_back(T &&t) { data -> push_back(std::move(t)); }

    void pop_back();

    T& front();
    T& back();
    //test 12.2
    const T& front() const;
    const T& back() const;

    T& operator[](size_type);
    const T& operator[](size_type) const;

    T& at(size_type);
    const T& at(size_type) const;
    //use count
    size_type use_count() const { return data -> use_count(); }
private:
    std::shared_ptr<vector<T>> data;
    //check index
    void check(size_type i, const string &msg) const;
};
//constructors
template <typename T>
Blob<T>::Blob() : data(std::shared_ptr<vector<T>>()) { }
template <typename T>
Blob<T>::Blob(initializer_list<T> il) : data(std::make_shared<vector<T>>(il)) { }

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<vector<T>>(b, e)) { }

//check index
template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
    if(i >= data -> size()) {
        throw std::out_of_range(msg);
    }
}
//pop_back
template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop back on empty Blob.");
    data -> pop_back();
}
//element access
template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob.");
    return data -> front();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data -> back();
}

template <typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data -> front();
}

template <typename T>
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data -> back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "index out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "index out of range");
    return (*data)[i];
}

template <typename T>
T& Blob<T>::at(size_type i) {
    check(i, "index out of range");
    return data -> at(i);
}

template <typename T>
const T& Blob<T>::at(size_type i) const {
    check(i, "index out of range");
    return data -> at(i);
}

template <typename T>
inline bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) == *(rhs.data);
}

template <typename T>
inline bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
inline bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *(lhs.data) < *(rhs.data);
}

template <typename T>
inline bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs || lhs < rhs);
}

template <typename T>
inline bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs > rhs);
}

template <typename T>
inline bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs < rhs);
}
#endif // TEST16_12_BLOB_H

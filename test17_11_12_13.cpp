#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

template <unsigned N>
class TestResult {
    template <unsigned M>
    friend ostream& operator<<(ostream&, TestResult<M>&);
public:

    TestResult() = default;
    TestResult(unsigned long long u) : ans(u) { }
    TestResult(const string &s) : ans(s) { }
    TestResult(const char* cp) : ans(cp) { }

    //required by test 17.12
    void set_answer(size_t index, bool answer = true) {
        ans.set(index, answer);
    }

    bool get_answer(size_t index) {
        return ans[index];
    }

    size_t size() const {
        return ans.size();
    }

private:
    bitset<N> ans;
};
template <unsigned N>
ostream& operator<<(ostream &os, TestResult<N> &tr) {
    os << tr.ans;
    return os;
}

int main() {
    //test 17.11
    TestResult<32> tr1(8);
    TestResult<10> tr2("1001010001");
    cout << tr1 << endl;
    cout << tr2 << endl;

    //test 17.13
    vector<bool> bvec = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    TestResult<10> tr3;
    for(size_t i = 0; i != bvec.size(); ++ i) {
        tr3.set_answer(i, bvec[i]);
    }
    cout << tr3 << endl;

    //test get_answer
    //notice: low bit in the head
    for(size_t i = 0; i != tr3.size(); ++ i) {
        cout << tr3.get_answer(i) << ends;
    }
    cout << endl;

    return 0;
}

#ifndef TEST16_2_COMPARE_H
#define TEST16_2_COMPARE_H
template <typename T>
int compare(const T &l, const T &r) {
    if(l < r) { return -1; }
    if(r < l) { return 1; }
    return 0;
}
#endif // TEST16_2_COMPARE_H

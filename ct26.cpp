#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(int a, int b) {
    return a < b;
}
long long solution(long long n) {
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    return stoll(str);
}
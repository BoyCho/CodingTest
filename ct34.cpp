#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string str = to_string(x);
    int dv = 0;

    for (int i = 0; i < str.size(); i++)
        dv += str[i] - '0';
    return !(bool)(x % dv);
}
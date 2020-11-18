#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    if (sqrtl(n) - (int)sqrtl(n) != 0)
        return -1;
    else
        return pow(sqrtl(n) + 1, 2);
}
/*
long long solution(long long n) {
    long long answer = sqrt(n);

    return powl(answer, 2) == n ? powl(answer + 1, 2) : -1;
}
*/
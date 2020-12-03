#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}
long long solution(int w, int h) {
    long long whole = (long long)w * h;
    int white = w + h - gcd(w, h);

    return whole - white;
}

int main() {
    cout << solution(99999999,99999999);
}

// 숫자 사용 시 자료형 조심
// double 소수점 53자리 이상을 넘기는 문제를 해결하고 싶으면, 계산의 나누기를 마지막으로 둔다